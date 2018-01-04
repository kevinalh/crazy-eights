# Crazy Eights

Game created as a proof of concept of Berkeley sockets. Still under construction.

This is an experiment so I'm using tools that are new to me as of this writing.
In particular, the project uses [Autotools](https://en.wikipedia.org/wiki/GNU_Build_System)
with the [Check](https://github.com/libcheck/check) unit-testing framework.

## Getting started

To build the project, use the following.

``` sh
autoreconf --install
./configure
make
```

### Testing

Running the tests can be done like this.

``` sh
make check
```