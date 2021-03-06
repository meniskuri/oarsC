# Shpargalka - Kapana ✨Magic✨

#### Cmd commands under Windows
###### cmd command	Description
###### Basics:
- `call ------------------ calls a batch file from another one`
- `cd ------------------ change directory`
- `cls ------------------ clear screen`
- `cmd ------------------ start command prompt`
- `color ------------------ change console color`
- `date	----------------- show/set date`
- `dir ----------------- list directory content`
- `echo ----------------- text output`
- `exit ----------------- exits the command prompt or a batch file`
- `find ----------------- find files`
- `hostname ----------------- display host name`
- `pause ----------------- pauses the execution of a batch file and shows a message`
- `runas ----------------- start a program as another user`
- `systeminfo ----------------- a long list of information about your computer`
- `shutdown ----------------- shutdown the computer`
- `sort ----------------- sort the screen output`
- `start ----------------- start an own window to execute a program or command`
- `taskkill ----------------- terminate a process or a application`
- `tasklist ----------------- display applications and related tasks`
- `time ----------------- display/edit the system time`
- `timeout ----------------- wait any time`
- `title ----------------- set title for prompt`
- `ver ----------------- display operating system version`
- `w32tm ----------------- setting time synchronisation/time server/time zone`

###### Network:
- `ftp ----------------- transfer files to a FTP server`
- `ftype ----------------- display file type and mapping`
- `getmac ----------------- display MAC address`
- `ipconfig ----------------- display IP network settings`
- `netsh ----------------- configure/control/display network components`
- `netstat ----------------- display TCP/IP connections and status`
- `nslookup ----------------- query the DNS`
- `pathping ----------------- test the connection to a specific IP address`
- `ping ----------------- pings the network`
- `route ----------------- display network routing table, add static routes`
- `systeminfo ----------------- displays computer-specific properties and configurations`
- `telnet ----------------- establish Telnet connection`
- `tftp ----------------- transfer files to a TFTP server`
- `tracert ----------------- trace routes similar to patchping`
- `netsh wlan show profile UTG key=clear ----------------- UTG ს პაროლს ნახავ`
- `ncpa.cpl ----------------- opens networ connections`
- `ipconfig/all ----------------- in order to find your local DNS server address`
- `msconfig ----------------- opems system configurations`

###### Files:
- `attrib ----------------- display file attributes`
- `comp ----------------- compare file contents`
- `compact -----------------	display/change file compression`
- `copy / xcopy ----------------- copy files`
- `mp ----------------- compare content of two floppy disks`
- `diskcopy ----------------- copy floppy disc to another one`
- `erase / del -----------------	delete one or more files`
- `expand ----------------- extract files`
- `fc ----------------- copare files and display the differences`
- `mkdir ----------------- create a new directory`
- `move ----------------- ove/rename files`
- `rename ----------------- rename files`
- `replace -----------------	replace files`
- `rmdir / rd ----------------- delete directory`
- `tree ----------------- display folder structure graphically`
- `type ----------------- display content of text files`

###### Media:
- `chkdsk ----------------- check volumes`
- `chkntfs -----------------	display/change volume check at startup`
- `defrag ----------------- defragment media`
- `diskpart ----------------- volume management`
- `driverquery -----------------	display installed devices and their properties`
- `format ----------------- format volumes`
- `label ----------------- change volume name`
- `mode ----------------- configure interfaces/devices`
- `mountvol ----------------- assign/delete drive mountpoints`
- `verify ----------------- monitoring whether volumes are written correctly`
- `vol -----------------	show volume description and serial numbers of the HDDs`

###### Miscellaneous:
- `for ----------------- for loop`
- `gpresult ----------------- display group policies`
- `gpupdate ----------------- update group policies`
- `perfmon ----------------- start performance monitor`
- `prompt ----------------- change command prompt`
- `reg ----------------- add/read/import/export registry entries`

###### KEYBOARD SHORTCUTS (windows 10)
- `Ctrl+Esc ----------------- Start Start`
- `Tab ----------------- კლავიატურით დაძვრები ფანჯრებში. და ისრებით შეგიძლია იარო`
- `Alt and spacebar ----------------- გახსნილი ფანჯრის გამორთვა ან მინიმიზირება ან გაზრდა-მოკლედ დააჭირე და ნახავ რა`
- `Windows key and down arrow ----------------- გადიდება შემცირება ფანჯრის`
- `Ctrl and Tab ----------------- To move left to right between tabs in the currently selected window`
- `Ctrl, Shift, and Tab ----------------- To move right to left between tabs in the currently selected window`
- `Alt key, then press the Tab key ----------------- Moving between open windows and application`

```
matlab -nosplash -nodesktop -r "whathever" (მატლაბის გაშვება)
```

#### GIT Bash
- `cd`
- `cd ..`
- `cd ../..`
- `cd ~/Desktop`
- `pwd`
- `clear`
- `ctrl + l ----------------- ჩამოწევს ფანჯარას და ვითომ გაწმინდა`
- `stat -c %s file.name ----------------- გაიგებ ფაილის ზომას, ბაიტებში. stat ბრძანება სანახავია stat --help`

```
GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Report any translation bugs to <https://translationproject.org/team/>
Full documentation <https://www.gnu.org/software/coreutils/stat>
```

- `echo "aq vinaxav teqsts" > text.txt -----------------  ში ჩაიწერება ის რაც echo "" ში დავწერე`
- `echo "aq vwer axal teqsts" > text.txt ----------------- თუ text.txt ში რამე ეწერა ეს ბრძანება წაშლის და თავიდან ახალ ტექსტს`
- `echo "aq vamateb teqsts" >> text.txt ----------------- ში ჩაამატებს ამ ჩანაწერს`

- `cat text.txt ----------------- დაბეჭდავს text.txt ში რაც წერია`
- `cat. text.txt text2.txt ----------------- დაბეჭდავს ყველა ფაილს რასაც მიუთითებ`
- `cat test_?.txt ----------------- ყველაფერს რაც cat test_ და აქ ცვლადი.txt სახით არის`
- `cat test_* ----------------- ყველაფერს რაც cat_test_ ით იწყება`
- `cat output.txt > test.txt ----------------- output.txt ში რაც წერია გადაწერს test.txt ში`
- `cat output* > test.txt ----------------- ყველა output ფაილს გადაიტანს test.txt ში`

- `dir ----------------- ვინდოუსზე- სადაც ხარ იქ ფაილებს და ფოლდერების სიას ჩამოგიწერს`
- `ls ----------------- ლინუქსზე- სადაც ხარ იქ ფაილებს და ფოლდერების სიას ჩამოგიწერს`
- `ls > output.txt ----------------- ფოლდერში სადაც ხარ. ნახავს სიას და ჩაწერს output.txt ში`
- `ls -t ----------------- ფაილების დროის მიხედვით სორტირება`
- `ls -a ----------------- all`
- `ls -al filename ----------------- ნახავ მეხსიერებას და როდის არის შექმნილი`

- `mkdir 1 2 ----------------- შექმნის 1 და 2 ფოლდერს`
- `mkdir -p gio1/gio2 ----------------- შექმნის ჩაშენებულ ფოლდერებს`

- `rm -r gio ----------------- წაშლის ფოლდერ gio -ს`
- `rm -r test_* ----------------- წაშლის ყველაფერს რაც იწყება test_ ით`

- `mkdir dir1 ----------------- შევქმნათ ფოლდერი`
- `mv text.txt dir1 ----------------- გადავიტანთ ფაილს ფოლდერში`
- `mv dir1/* . ----------------- dir1 ფოლდერიდან ყველა ფაილს გადმოიტანს უკან parent ფოლდერში`
- `mv dir2/ragac.txt dir3/dir4 ----------------- dir2 დან ragac.txt ფაილს გადაიტანს dir4 ში`

- `mv shargalka_reser.txt dir1 ----------------- ში გადავიტანოთ ფაილი`
- `cp dir1/shpargalka_reserv.txt . ----------------- შემდეგ უკან parent ფოლდერში გავაკეთოთ მისი კოპია`
- `cp shargalka.txt shargalka_copy.txt ----------------- დავაკოპირებ ჩემს ფაილს`
- `mv shpargalka_reserv.txt reserv_shpargalka.txt ----------------- ფაილეს შეუცვლის სახელს`
- `mv "folder 1" folder_1 -----------------`
- `mv "folder 2" folder_2 -----------------`
- `mv "folder 3" folder_3 -----------------`
- `mv "folder 4" folder_4 -----------------`
- `mv "folder 5" folder_5 -----------------`
- `mv "folder 6" folder_6 ----------------- ()`

- `rmdir folder ----------------- წაშლის ფოლდერს თუ ის ცარიელია`
- `rm -r folder ----------------- წაშლის ყველაფერს`

- `wc -l ----------------- word count - line count`
- `wc -l shpargalka.txt ----------------- დათვლის რამდენი ხაზია ჩემს ტექსტურ ფაილში. ასევე შესაძლებელია სიტყვების ბაიტების და ასე შემდეგ დათვლა wc --help`

- `ls > test.txt ----------------- ჩაწერს რამდენი ფაილი და ფოლდერია იქ სადაც ხართ`
- `ls ~ > test.txt ----------------- ჩაწერს რუთ დირექტორიიდან რამდენი ფოლდერი და ფაილია. მგონი. ნუ სანახავია ზუსტად რას იზავს`

- `cat shpargalka.txt |uniq|wc -l ----------------- პიპინგი shpargalka.txt ში uniq ბრძანებით და შემდეგ wc -l ით დავითვლით რამდენი უნიკალური ლაინია)
(ესეთი ჯაჭვი შეგვიძლია ავაგოთ უსასრულოდ დიდი და როგორიც გვჭირდება. ბრძანებების მიმდევრობაა ფაქტიურად)`

- `cmd //c tree ----------------- gnu bash tree windows`

- `./BBC.exe ----------------- To run a program in the current directory in bash, you put ./ in front of it.`

- `notepad shpargalka.txt & ----------------- txt ფაილის ან სხვა ტიპის ფაილების გახსნა with bash`

#### GIT
- `Ctrl+L ----------------- To clear your screen`
- `rm -rf .git ----------------- როცა ხარ გიტ რეპოზიტორში (master) remove the git sub directory, we will lose this repository)`

- `git init`
- `git log`
- `git log --graph`
- `git status`
- `git status -s`

- `git add file1.txt file2.txt`
- `git add *.txt ----------------- all txt files`
- `git add . ----------------- ყველაფერს დაამატებს რაც ფოლდერშია`

- `git restore file1.txt ----------------- თუ რამეს შეცვლი ფაილში და მისი გაუქმება გინდა - use "git restore <file>" to discard changes in working directory`
- `git rm cached file1.txt`
- `git rm file1.txt`

- `git config --global -e`

<https://github.com/meniskuri/gitignore>

- `echo logs/> .gitignore -----------------სხვადასხვა საქმისთვის სხვადასხვა გიტ იგნორის თემფლეითი შემიძლია შევარჩიო გითჰაბიდან`
- `atom .gitignore & ----------------- რისი ტრეკინგის დაიგნორებასაც ვაპირებთ ეგ ფაილი. და მანდ ეწერება`

- `git commit -m “Message” ----------------- Commits with a one-line message`
- `git commit ----------------- Opens the default editor to type a long message`
- `git commit -a ----------------- commit all`
- `git commit -am "massage" ----------------- commit all with a massage`
- `git show 921a2ff ----------------- Shows the given commit`
- `git show HEAD ----------------- Shows the last commit`
- `git ls-files`

- `git diff ----------------- Shows unstaged changes`
- `git diff --staged ----------------- Shows staged changes`
- `git diff --cached ----------------- Same as the above`

> If you want to temporarily go back to it, fool around, then come back to where you are,
> all you have to do is check out the desired commit:
> This will detach your HEAD, that is, leave you with no branch checked out:

- `git checkout 0d1d7fc32`

- `git checkout master ----------------- მასტერ ტოტზე დაბრუნება`

> Or if you want to make commits while you're there, go ahead and make a new branch while you're at it:

- `git checkout -b old-state 0d1d7fc32 ----------------- ბრენჩის გაკეთება`


###### Managing branches, Branching & Merging
- `git branch bugfix ----------------- Creates a new branch called bugfix`
- `git branch ----------------- To see local branches, run this command`
- `git branch -r ----------------- To see all the remote branches`
- `git branch -d localBranchName ----------------- delete branch locally`
- `git push origin --delete remoteBranchName ----------------- delete branch remotely`
- `git checkout bugfix ----------------- Switches to the bugfix branch`
- `git switch bugfix ----------------- Switches to the bugfix branch`
- `git switch -C bugfix ----------------- Creates and switches`


###### Comparing branches, Branching & Merging
- `git log master..bugfix ----------------- Lists the commits in the bugfix branch not in master`
- `git diff master..bugfix ----------------- Shows the summary of changes`

###### Merging, Branching & Merging
###### Viewing the merged branches, Branching & Merging


```
// git repository ის tree ს ნახვა (ვიზუალიზაცია) თავისი მასტერით და ბრენჩებით) ## V1
git config --global alias.lgb "log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s
%Cgreen(%cr) %C(bold blue)<%an>%Creset%n' --abbrev-commit --date=relative --branches"
git lgb
// V2
git log --graph --pretty=oneline --abbrev-commit
```



###### Learn how to perform Git PUSH and PULL requests through GitHub Desktop and the Command-Line

<https://www.datacamp.com/community/tutorials/git-push-pull> აქ შეგიძლია ნახო ტუტორიალი.


> The git push command is used to transfer or push the commit, which is made on a local branch in your
> computer to a remote repository like GitHub. The command used # for pushing to GitHub is given below.

> Git remote add origin 'your_url_name' (Add the URL copied, which is your remote repository to where your
> local content from your repository is pushed)


###### Push the code in your local repository to GitHub

- `git push -u origin master ----------------- is used for pushing local content to GitHub.  '-u' flag is upstream`
```
// აქ მაქვს ჩემი ერთი რეპოზიტორი მიბმული ✨Magic✨
git push -u C_Raylib_Snake_os master
```

> - Pushing commits to a remote repository (ლოკალიდან რემოუთზე აფუშვა)
>  - A remote name, for example, origin
>  - A branch name, for example, main

- `git push  REMOTENAME BRANCHNAME ----------------- local იდან remote ზე ატვირთვა ცვლილებების`


###### PULL Request through Command Line

> The git pull command is a combination of git fetch which fetches the recent commits in the local repository and git merge,
> which will merge the branch from a remote to a local branch also 'remote_name' is the repository name and 'branch_name'
> is the name of the specific branch.
> <https://www.datacamp.com/community/tutorials/git-push-pull> შენს რეპოზიტორში შეგიძლია შეცვალო რამე.
> შემდეგ შექმნა ახალი ბრენჩი. დააკომიტო და აფუშო. შემდეგ შექმნა ფულ რექვესთი.
> როცა ნებას მოქცემენ და დამერჯავ ცვლილებას, ბრენჩი რომელიც შექმნილია ცვლილებისთის შეგიძლია წაშალო.

- `git pull ----------------- თუ ხარ local საცავში და remote საცავიდან განახლება გინდა. თუ უკვე დაკლონილი გყავს ან მიბმული ხარ რეპოზიტორზე`


###### Cloning a repository

- <https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository>  აქ შეგიძლია ნახო ტუტორიალი
- <https://github.com/YOUR-USERNAME/YOUR-REPOSITORY> Type git clone, and then paste the URL you copied earlier

###### Connecting to GitHub with SSH


##### Getting Python Shell To Work on Git Bash — Windows, Mac, Linux

- `winpty python ----------------- Both of these commands will activate the Python shell. for 'winpty python' you can exit the IDLE using CTRL + Z or exit()`
- `python -i ----------------- Both of these commands will activate the Python shell. for 'python -i' you can exit with only exit()`


> tamris chveneba # aq var
> Edsger W. Dijkstra -- <<<< სანახავია
> ალან კეი, კომპიუტერული რევოლუცია ჯერ არ მომხდარა -- <<<< სანახავია (1997 წლის კონფერენცია - რევოლუცია ჯერ არ მომხდარა რაღაცა მართლა მოღუნულად არის)
> ტიურინგის მანქანა -- მაგნიტური ლენტი ჭირდება -- <<<< სანახავია
> T  ენა ;)
> Linux kernel
