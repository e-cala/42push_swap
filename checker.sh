#!bin/bash

PUSH_SWAP=./push_swap
CHECKER=./checker/checker_linux

GREEN="\e[32m"
RED="\e[91m"
YELLOW="\e[33m"
BOLD="\e[1m"
RESET="\e[0m"

echo "
..................................
.         STARTING TESTS         .
.................................."

checker3()
{
#ARG=$(jot -r 3 -1003 1003 | awk '{printf "%i ",$0}')
COMMAND=$($PUSH_SWAP $ARG | $CHECKER $ARG)
RE=$(if [ $COMMAND = 'OK' ]; then
	echo "${GREEN}${COMMAND}"
elif [ $COMMAND = 'KO' ]; then
	echo "${RED}${COMMAND}"
fi)
	echo "${YELLOW}[Test   3]${RESET} $RE $RESET\t Instructions ($($PUSH_SWAP $ARG | wc -l)) => $ARG"
}


checker4()
{
#ARG=$(jot -r 4 -1004 1004 | awk '{printf "%i ",$0}')
COMMAND=$($PUSH_SWAP $ARG | $CHECKER $ARG)
RE=$(if [ ${COMMAND} = 'OK' ]; then
	echo "${GREEN}${COMMAND}"
elif [ $COMMAND = 'KO' ]; then
	echo "${RED}${COMMAND}"
fi)
	echo "${YELLOW}[Test   4]${RESET} $RE $RESET\t Instructions ($($PUSH_SWAP $ARG | wc -l)) => $ARG"
}

checker5()
{
#ARG=$(jot -r 5 -1005 1005 | awk '{printf "%i ",$0}')
COMMAND=$($PUSH_SWAP $ARG | $CHECKER $ARG)
RE=$(if [ ${COMMAND} = 'OK' ]; then
	echo "${GREEN}${COMMAND}"
elif [ $COMMAND = 'KO' ]; then
	echo "${RED}${COMMAND}"
fi)
	echo "${YELLOW}[Test   5]${RESET} $RE $RESET\t Instructions ($($PUSH_SWAP $ARG | wc -l)) => $ARG"
}

checker100()
{
#ARG=$(jot -r 100 -1000000 1000000 | awk '{printf "%i ",$0}')
COMMAND=$($PUSH_SWAP $ARG | $CHECKER $ARG)
RE=$(if [ ${COMMAND} = 'OK' ]; then
	echo "${GREEN}${COMMAND}"
elif [ $COMMAND = 'KO' ]; then
	echo "${RED}${COMMAND}"
fi)
	echo "${YELLOW}[Test 100]${RESET} $RE $RESET\t Instructions ($($PUSH_SWAP $ARG | wc -l)) "
}

checker500()
{
#ARG=$(jot -r 500 -1000000 1000000 | awk '{printf "%i ", $0}')
COMMAND=$($PUSH_SWAP $ARG | $CHECKER $ARG)
RE=$(if [ ${COMMAND} = 'OK' ]; then
	echo "${GREEN}${COMMAND}"
elif [ $COMMAND = 'KO' ]; then
	echo "${RED}${COMMAND}"
fi)
	echo "${YELLOW}[Test 500]${RESET} $RE $RESET\t Instructions ($($PUSH_SWAP $ARG | wc -l)) "
}

################

loop()
{
list='1 2 3 4 5 6 7 8 9 10'
for i in $list
do
	ARG=$(jot -s ' ' -r $num $MIN $MAX)
	$TEST $ARG
#	sleep .7
done
echo "\n"
}

TEST=checker3 
num=3
MIN=-1000
MAX=1000
loop "$TEST" "$num" "$MIN" "$MAX"

TEST=checker4
num=4
loop "$TEST" "$num" "$MIN" "$MAX"

TEST=checker5
num=5
loop "$TEST" "$num" "$MIN" "$MAX"

TEST=checker100
num=100
MIN=-1000000
MAX=1000000
loop "$TEST" "$num" "$MIN" "$MAX"


TEST=checker500
num=500
loop "$TEST" "$num" "$MIN" "$MAX"

