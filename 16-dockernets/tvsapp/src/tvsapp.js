import express from 'express';
import fetch from 'node-fetch';

const DEFAULT_ELASTIC_URL = "http://localhost:9200";

const NODE_PORT   = process.env["NODE_PORT"];
const ELASTIC_URL = process.env["ELASTIC_URL"] || DEFAULT_ELASTIC_URL;

///////////////////////////////////////////////////////
//
// Server: Listen on NODE_PORT and serve the homepage
//

if (!NODE_PORT) {
	process.stderr.write("ERROR: missing NODE_PORT configuration variable\n");
	process.exitCode = 1;
} else {
	const app = express();
	app.get("/", getHomePage);
	app.listen(NODE_PORT);
}

///////////////////////////////////////////////////////
//
// The only service available: 
//   - increment access counter
//   - inform about listening port and current count
//

async function getHomePage(req, res) {
	const port = NODE_PORT;
	const counter = await incrementAndGetCounter();
	
	const homePage = buildHomePage(port, counter);
	
	res.send(homePage);
}

///////////////////////////////////////////////////////
//
// Data access: 
//   - atomically increment the access counter
//   - return the current count
//   - returns undefined if database is unavailable
//

async function incrementAndGetCounter() {
	try {
		const response = await fetch(`${ELASTIC_URL}/stats/_update/1?retry_on_conflict=8&_source=counter`,
		{
			method: 'post',
			headers: {'Content-Type': 'application/json'},
			body: JSON.stringify({
					"script" : {
						"source": "ctx._source.counter += params.count",
						"lang": "painless",
						"params": {
							"count": 1
						}
					},
					"upsert": {
						"counter": 1
					}
				}
			),
		});
		const answer = await response.json();
		return answer.get._source.counter;
	} catch (err) {
		console.error(err);
		return null;
	}
}

///////////////////////////////////////////////////////
//
// Build homepage: 
//   - title
//   - show listening port
//   - show counter, if available
//

function buildHomePage(port, counter) {
	return `
		<html>
			<body>
				<h1>TVS Application</h1>
				<p><strong>PORT: </strong>${port}</p>
				<hr>
				${
					counter ?
						`<p style="font-size: 1200%; font-family: sans-serif">${counter}</p>`
						:
						`<br><p style="color: red; font-style: italic">(database unavailable)</p>`
				 }
			</body>
		</html>
	`;
}
