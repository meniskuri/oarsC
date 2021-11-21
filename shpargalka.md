# Shpargalka - Kapana ✨Magic✨

#### C and C Raylib
> Compilation is the translation of source code (the code we write)
> into object code (sequence of statements in machine language) by a compiler.
> - The compilation process has four different steps:
>  - The preprocessing
>  - The compiling
>  - The assembling
>  - The linking

დეტალურად იხილეთ ლინკი: <https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052>

`როგორ იბილდება? 1.პრე კომპილაცია 2. კომპილაცია 3. ლინკინგი | ასემბლი`
##### The steps
1. The preprocessor
> The output of this step will be stored in a file with a “.i” extension
 - `gcc -E file1.c`       (In order to stop the compilation right after this step,
 we can use the option “-E” with the gcc command on the source file and press enter.)

2. The compiler
> The compiler will take the preprocessed file and generate IR code (Intermediate Representation), so this will produce a `“.s”` file.
 - `gcc -S file1.c`       (We can stop after this step with the `“-S”` option on the `gcc` command, and press enter. and then `cat file1.s`)

3. The assembler
> The assembler takes the IR code and transforms it into object code, that is code in machine language (i.e. binary). This will produce a file ending in “.o”.
(IR code - Intermediate Representation <https://en.wikipedia.org/wiki/Intermediate_representation>
 - `gcc -c file1.c`       (We can stop the compilation process after this step by using the option “-c” with the gcc command, and pressing enter.)
დაამზადებს ობჯექთ ფაილს. `gcc file1.o` დაამზადებს `a.exe` ფაილს.

4. The linker
> The linker creates the final executable, in binary, and can play two roles:
  - linking all the source files together, that is all the other object codes in the project. For example, if I want to compile `main.c` with another file called         `secondary.c` and make them into one single program, this is the step where the object code of secondary.c (that is secondary.o) will be linked to the main.c
    object code `(main.o)`.
> second
  - linking function calls with their definitions. The linker knows where to look for the function definitions in the static libraries or dynamic libraries. Static     libraries are “the result of the linker making copy of all used library functions to the executable file”, according to geeksforgeeks.org, and dynamic libraries     “don’t require the code to be copied, it is done by just placing the name of the library in the binary file”. Note that gcc uses by default dynamic libraries. In     our example this is when the linker will find the definition of our “puts” function, and link it.

 >  - By default, after this fourth and last step, that is when you type the whole `gcc main.c` command without any options, the compiler will create an executable program called `a.out`, that we can run by typing “./a.out” in the command line.

 > - `gcc file1.c -o file1`             (We can also choose to create an executable program with the name we want, by adding the “-o”)
> - `gcc –Wall filename.c –o filename` (The option -Wall enables all compiler’s warning messages. This option is recommended to generate better code.)

##### Automatic build with makefile
> Tutorial: <https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/> (how to make simple Makefile)

Let's start off with the following three files, `hellomake.c, hellofunc.c, and hellomake.h`,
which would represent a typical main program, some functional code in a separate file,
and an include file, respectively.

```
hellomake.c	hellofunc.c	hellomake.h
```
```
// hellomake.c
#include <hellomake.h>

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
```
```
// hellofunc.c
#include <stdio.h>
#include <hellomake.h>

void myPrintHelloMake(void) {

  printf("Hello makefiles!\n");

  return;
}
```
```
// hellomake.h

/*
example include file
*/

void myPrintHelloMake(void);
```

> `hellomake.c` `hellofunc.c` და `compile this collection of code` და `hellomake.h` და მიაბი.

Normally, you would compile this collection of code by executing the following command:
> gcc -o hellomake hellomake.c hellofunc.c -I.    (This compiles the two .c files and names the executable hellomake. The -I. is included so that gcc will look in the current directory (.) for the include file hellomake.h. Without a makefile)

The simplest makefile you could create would look something like:
###### Makefile 1
```
hellomake: hellomake.c hellofunc.c
      gcc -o hellomake hellomake.c hellofunc.c -I.

 make (ბრძანებით გაუშვებ ამ მეიკფაილს)
```

One very important thing to note is that there is a tab before the gcc command in the makefile. There must be a tab at the beginning of any command, and make will not be happy if it's not there.


In order to be a bit more efficient, let's try the following:
###### Makefile 2
```
CC=gcc
CFLAGS=-I.

hellomake: hellomake.o hellofunc.o
      $(CC) -o hellomake hellomake.o hellofunc.o
```
> So now we've defined some constants CC and CFLAGS. It turns out these are special constants that communicate to make how we want to compile the files hellomake.c and hellofunc.c. In particular, the macro CC is the C compiler to use, and CFLAGS is the list of flags to pass to the compilation command. By putting the object files--hellomake.o and hellofunc.o--in the dependency list and in the rule, make knows it must first compile the .c versions individually, and then build the executable hellomake.

> Using this form of makefile is sufficient for most small scale projects. However, there is one thing missing: dependency on the include files. If you were to make a change to hellomake.h, for example, make would not recompile the .c files, even though they needed to be. In order to fix this, we need to tell make that all .c files depend on certain .h files. We can do this by writing a simple rule and adding it to the makefile.

```
თუ გამოვიყენებთ ბრძანება make -ს:
 - აქ მოგიწევს ობჯექთ ფაილების შექმნა ხელით gcc -c filename.c -I.

თუ გამოვიყენებთ ბრძანება mingw32-make:
 - makefile (N2 ვარიანტი) იმუშავებს სწორად და შექნის ობჯექთ ფაილებს თვითონ. შემდეგ კი ეგზეს.

```

###### Makefile 3
```
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
      $(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o
      $(CC) -o hellomake hellomake.o hellofunc.o
```
> This addition first creates the macro `DEPS`, which is the set of `.h` files on which the `.c` files depend. Then we define a rule that applies to all files ending in the `.o` suffix. The rule says that the `.o` file depends upon the `.c` version of the file and the .h files included in the `DEPS` macro. The rule then says that to generate the `.o` file, make needs to compile the `.c` file using the compiler defined in the `CC` macro. The `-c flag` says to generate the object file, the `-o $@` says to put the output of the compilation in the file named on the left side of the :, the `$<` is the first item in the dependencies list, and the `CFLAGS` macro is defined as above.

> As a final simplification, let's use the special macros `$@` and `$^`, which are the left and right sides of the :, respectively, to make the overall compilation rule more general. In the example below, all of the include files should be listed as part of the macro `DEPS`, and all of the object files should be listed as part of the macro `OBJ`.

###### Makefile 4
```
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o: %.c $(DEPS)
      $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
      $(CC) -o $@ $^ $(CFLAGS)
```
> So what if we want to start putting our `.h` files in an `include` directory, our source code in a `src` directory, and some local libraries in a `lib` directory? Also, can we somehow hide those annoying `.o` files that hang around all over the place? The answer, of course, is yes. The following `makefile` defines paths to the `include` and `lib` directories, and places the object files in an `obj` subdirectory within the `src` directory. It also has a macro defined for any libraries you want to include, such as the `math library -lm`. This makefile should be located in the `src` directory. Note that it also includes a rule for cleaning up your source and object directories if you type make `mingw32-make clean`. The `.PHONY` rule keeps make from doing something with a file named `mingw32-make clean`.


###### Makefile 5
```
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
      $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
      $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
      rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

```
> So now you have a perfectly good `makefile` that you can modify to manage small and medium-sized software projects. You can add multiple rules to a `makefile`; you can even create rules that call other rules. For more information on `makefiles` and the `make` function, check out the `GNU Make Manual`, which will tell you more than you ever wanted to know (really).

/* აქ ვარ გაჭედილი - ჩემს make ბრძანებას არ ესმის გარკვეული სიმბოლოები. გადმოვწერე mingw32-make*/

###### Makefile (tutorial 2)
<https://makefiletutorial.com/> ტუტორიალი 2 (ვნახოთ - გადასახედია)



##### Optimization and Options
```
gcc -O3 -S arraysTest1.c (მესამე დონის ოპტიმიზაცია - ასემბლერის ფაილის დამზადებისას -- კიდევ მაქვს კითხვები ??? წასაკითხია რაღაცეები ;) )

```

##### GDB
###### How to Debug C Program using gdb in 6 Simple Steps
```
gcc -g file1.c    (Compile your C program with -g option. This allows the compiler to collect the debugging information.)
                  (The above command creates a.out file which will be used for debugging as shown below. or a.exe)
gdb a.exe         (Launch gdb)
break line_number (ბრეიქ პონტის დასმა და რა ადგილას სვავ line_number = 12 მაგალითად)
run               (Execute the C program in gdb debugger)
print {variable}  (Printing the variable values inside gdb debugger)

s                 (or step: Same as next, but does not treats function as a single instruction, instead goes into the function and executes it line by line.)
c                 (or continue: Debugger will continue executing until the next break point.)
n                 (or next: Debugger will execute the next line as single instruction.)
l                 (lisტ)

q                 (quit)
```

##### How to Debug C Raylib using gdb
```
gcc -o core_input_keys.exe core_input_keys.c C:\\raylib\\raylib\\src\\raylib.rc.data
-std=c99 -Wall -IC:\\raylib\\raylib\\src -Iexternal -DPLATFORM_DESKTOP -ggdb -lraylib
-lopengl32 -lgdi32 -lwinmm^C
```
#### Atom
```
ctrl shift p     (შეგიძლია ნახო ექსთენშენები რაც გაქვს დაყენებული მაგალითად. აკრიფე Gpp და ამოგიგდებს რომ f5 ით უშვებ სის - GCC)
f5               (compile C/C++)
f6               (compiler GDB - GNU Project Debugger - მაგრამ გამოყენება ჯერ არ ვიცი)
cntrl g          (და შეიყვან რიცხვს რომელ ლაინზეც გინდა გადახტე კოდში)
```
- ctrl-alt-o


#### Vim

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
