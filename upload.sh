# !/bin/bash

if [ $# != 2 ] ; then 
	echo sh upload.sh "server[csie1, oop]" "dir_name"
	exit 1; 
fi 
if [ $1 == "csie1" ] ; then
	serv="csie1.cs.ccu.edu.tw"
	echo $serv
	echo "Uploading $2..."
	ncftp -u "lpz106u" -p "k0930383100"  $serv << EOF
put -R $2
quit
EOF
fi

if [ $1 == "oop" ] ; then

	file="406410029_v4.tar.gz"

	tar zcvf $file ./$2/*
	serv="ftp://damon.hpc.tw:410/"
	echo $serv
	cd $2
	echo "Uploading $2..."
#	ncftp put -R -u "oop" -p "oop" $2 406410029.tar.gz
	cd ..
	ncftp -u "oop" -p "oop"  $serv << EOF
cd $2
put $file
quit
EOF
	rm -f 406410029*.tar.gz
fi

exit 1
