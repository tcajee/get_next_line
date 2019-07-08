#! /bin/bash
make fclean
rm -rf testfds.out test1.out
make
./test_gnl
