import flask
from flask import request
import logging
import os

app = flask.Flask(__name__)

@app.route("/")
@app.route("/index")
def index():
	return flask.render_template('twit.html')

@app.route("/submit", methods=["POST"])
def submit():
	string1 = request.form["category"]
	string2 = request.form["text"]
#	app.logger.debug(string1)
#	app.logger.debug(string2)
	f = open("hack_test.txt", "w")
	f.write(string1 + "\n")
	f.write(string2)
	f.close()
	# os.system("cat hack_test.txt")	
	os.system("make -C ../twitbot web")
	os.system("../twitbot/web_bot.exe")	
#	test.test1(string1, string2)
	return flask.render_template('twit.html')
app.debug = True
if app.debug:
    app.logger.setLevel(logging.DEBUG)

if __name__ == "__main__":
    print("Opening for global access on port {}".format(5000))
    app.run(port=5000, host="0.0.0.0")
