FROM rust:1.41-buster

WORKDIR /root/howfast

RUN cargo install cargo-edit

RUN apt update
RUN apt install man
