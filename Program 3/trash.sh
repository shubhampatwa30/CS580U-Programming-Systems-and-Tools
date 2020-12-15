#!/bin/bash
for i in $@
do
	 
	if [ -e $i ];then 
		if [ -d trash ]; then 
				mv $i trash
				echo " $i successfully moved to trash folder "
			else
				mkdir trash
				echo " Trash folder created "
				mv $i trash
				echo " $i successfully moved to trash folder "
	fi

		else
		echo "$i doesn't exist "

fi
done
if [ -d trash ]; then
find trash -mmin +60 -delete
echo " File(s) more than 60 mins (if any) in trash folder have been deleted "
else
echo " No trash folder found "
fi
