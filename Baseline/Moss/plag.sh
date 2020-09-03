python3 plag.py
while ! [ $? -eq 0 ]
do
    echo 'Trying'
    echo $?
    python3 plag.py
done