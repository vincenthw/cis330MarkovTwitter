from flask import Flask, render_template
from flask import request
import logging
import os

# app = flask.Flask(__name__)
app = Flask(__name__)

@app.route("/")
@app.route("/index")
def index():
	return render_template('twit.html')#flask.render_template('twit.html')

@app.route("/submit", methods=["POST"])
def submit():
	#Extracting the variable input from the users submitted form
	string1 = request.form["category"]
	string2 = request.form["text"]
	ls_cats = string2.split()
	app.logger.debug(ls_cats)
	f = open("hack_test.txt", "w")
	f.write(string1 + "\n")
	if len(ls_cats) != 0:
		for val in ls_cats:
			f.write(val)
	else:
		f.write(string2)
	f.close()	
	#os.system("make -C ../twitbot web")
	#os.system("../twitbot/web_bot.exe")	
	return render_template('twit.html')#flask.render_template('twit.html')
app.debug = True
if app.debug:
    app.logger.setLevel(logging.DEBUG)

if __name__ == "__main__":
    print("Opening for global access on port {}".format(5000))
    app.run(port=5000, host="0.0.0.0")
