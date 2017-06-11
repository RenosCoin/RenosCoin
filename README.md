# RenosCoin

Renos is a PoS-based cryptocurrency.

Renos uses libsecp256k1,
			  libgmp,
			  Boost1.55,
			  OR Boost1.57,  
			  Openssl1.01p,
			  Berkeley DB 4.8,
			  QT5 to compile


Block Spacing: 90 Seconds
Stake Minimum Age: 6 Hours

Port: 57155
RPC Port: 57154


BUILD LINUX
-----------
1) git clone https://github.com/RenosCoin/RenosCoin.git RenosCoin

2) cd RenosCoin/src

3) sudo make -f makefile.unix            # Headless renos

(optional)

4) strip renosd

5) sudo cp renosd /usr/local/bin




BUILD WINDOWS
-------------

1) Download Qt.zip from https://github.com/RenosCoin/RenosCoin/releases/tag/v1.0 and unpack to C:/

2) Download RenosCoin source from https://github.com/RenosCoin/RenosCoin/archive/master.zip 

2.1) Unpack to C:/RenosCoin

3) Install Perl for windows from the homepage http://www.activestate.com/activeperl/downloads

4) Download Python 2.7 https://www.python.org/downloads/windows/

4.1) While installing python make sure to add python.exe to the path.

5) Run msys.bat located in C:\MinGW49-32\msys\1.0

6) cd /C/RenosCoin/src/leveldb

7) Type "TARGET_OS=NATIVE_WINDOWS make libleveldb.a libmemenv.a" and hit enter to build leveldb

8) Exit msys shell

9) Open windows command prompt

10) cd C:/dev

11) Type "49-32-qt5.bat" and hit enter to run

12) cd ../RenosCoin

13) Type "qmake USE_UPNP=0" and hit enter to run

14) Type "mingw32-make" and hit enter to start building. When it's finished you can find your .exe in the release folder.
