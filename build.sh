if [ "$1" == "build" ]; then

	if [ ! -d "build" ]; then
        	mkdir build
	fi

	cd build 

	cmake ~/space/unn-lab3/
	make
	cd ..
fi

if [ "$1" == "run" ]; then 
	cd build
	./application/unn-lab3
	cd ..
fi 

if [ "$1" == "all" ]; then
	source build.sh build
	source build.sh run
fi

