INDEX=20
NB_KEY=1000000
NB_TEST=1000000

BEGIN=$((($NB_KEY+1)*2))
END=$(($BEGIN + $NB_TEST))

gcc generate_test.c -o generator
./generator $NB_KEY $NB_TEST > infile/infile_$INDEX

cat infile/infile_$INDEX | sed "$BEGIN,$END!d" | sed "s/key/value/g"  >expected/outfile_$INDEX
# cat infile/infile_$INDEX | sed "$BEGIN,$END!d" | awk '{print $0": Not found."}'  >expected/outfile_$INDEX