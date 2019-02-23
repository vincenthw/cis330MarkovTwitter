FROM ubuntu:latest
RUN apt-get update -y
RUN apt-get install -y libcurl4-openssl-dev git make
RUN git clone https://github.com/swatkat/twitcurl.git
RUN cd twitcurl/libtwitcurl
RUN make all
RUN apt-get install -y libjsoncpp-dev
COPY . /Twitbot
WORKDIR /Twitbot
RUN make
RUN ./twitterTest