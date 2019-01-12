echo {1..1000}\\n > tmpfile0
head -n 1000 tmpfile0 > tmpfile
rm tmpfile0

mkdir d0

while read p; do
  touch d0/$p
done < tmpfile

cp -R d0 d0/d1
