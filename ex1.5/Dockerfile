# sudo docker build -t ex2 .
# sudo docker run -d -p 8885:8885 --rm -it ex2

FROM ubuntu:22.04

RUN apt-get update

RUN useradd -d /home/ept/ -m -p ept -s /bin/bash ept
RUN echo "ept:ept" | chpasswd

WORKDIR /home/ept

COPY ynetd .
COPY flag.txt /opt/flag
COPY ex1.5 .

RUN chown -R root:root /home/ept
RUN chmod  -R a+rx /home/ept
USER ept
CMD ./ynetd -p 8884 ./ex1.5
