#!/bin/bash

_download () {
	rm -rf opt
	mkdir -p opt/mvcli

	pushd opt/mvcli

	wget https://dl.dell.com/FOLDER06354567M/1/mvcli_5.0.13.1109_A00.zip
	unzip mvcli_5.0.13.1109_A00.zip

	mv x64/cli/{libmvraid.so,mvcli} .
	chmod +x mvcli

	rm -f mvcli_5.0.13.1109_A00.zip
	rm -rf i386/ x64/

	popd
}

_patch () {
	pushd opt/mvcli

	gcc -c -Wall -Werror -fpic ../../gcompat2.c
	gcc -shared -o libgcompat2.so gcompat2.o
	rm -f gcompat2.o

	patchelf --add-needed /opt/mvcli/libgcompat2.so mvcli
	patchelf --replace-needed libmvraid.so /opt/mvcli/libmvraid.so mvcli

	popd
}

_tarball() {
	tar cvzf alpine-mvcli-5.0.13.1107_A06.tar.gz opt/
}

_download
_patch
_tarball

