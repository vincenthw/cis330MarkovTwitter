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

	#splitting string2 into array incase there are multiple inputs
	ls_cats = string2.split()
	app.logger.debug(ls_cats)

	#open file to write in data that C++ function will access
	f = open("hack_test.txt", "w")

	#write the method selected to the file
	f.write(string1 + "\n")

	#check to see if multiple categories or user were input is so write each one on its own line in outfile
	if len(ls_cats) != 0:
		for val in range(0, len(ls_cats)-1):
			app.logger.debug(val)
			f.write(ls_cats[val] + "\n")
	else:
		f.write(string2)
	f.write(ls_cats[-1])
	f.close()

	#execute commands to execute the C++ webpageDriver.cpp
	os.system("../twitbot/web_bot.exe")	
	return render_template('twit.html')


app.debug = True
if app.debug:
    app.logger.setLevel(logging.DEBUG)

if __name__ == "__main__":
    print("Opening for global access on port {}".format(5000))
    app.run(port=5000, host="0.0.0.0")
