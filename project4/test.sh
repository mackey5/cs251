 #!/bin/nash
 for i in `seq 1 10000`;
 do
   cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1 >> in3.txt
   done
   ./program 1 in3.txt out3.txt 7 ./testdata/chunks/
   for j in `seq 1 1000`;
   do
     inString=`cat out3.txt | head -$j | tail -1`
       ./program 2 out3.txt $inString
       done
       echo "none of these should be found"
       for k in `seq 1 30`;
       do
         inString2=`cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1`
	   ./program 2 out3.txt $inString2
done
