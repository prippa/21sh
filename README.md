# 21sh
Project from UNIX branch in school 42

## Project 21sh is the continuation of the project [minishell](https://github.com/prippa/minishell)
### New in 21sh project

## Mandatory implementations
[✓] Pipes '**|**'

[✓] The 4 following redirections '**<**', '**>**', '**<<**' and '**>>**'

[✓] File descriptor aggregation '**<&**' and '**>&**'

[✓] Basic line editing features using **termcap library**

## Bonuses

[✓] Implementation of **Hash Table** for binary files, also the **hash** builtin command

[✓] Advanced auto completion using **tab**

[✓] Search through history using **ctrl+R**

[✓] Some other line editing features (see below)

## Hotkey list for line editing:

| Key |  | Details |
| --- | --- | --- |
| Left | ← | move cursor backward by one character |
| Right | → | move cursor forward by one character |
| Up | ↑ | List term history up |
| Down | ↓ | List term history down |
| Ctrl + Left | ⌃← | move cursor backward by one word |
| Ctrl + Right | ⌃→ | move cursor forward by one word |
| Ctrl + Up | ⌃↑ | move cursor backward by one row |
| Ctrl + Down | ⌃↓ | move cursor forward by one row |
| Ctrl + Shift + Left | ⌃⇧← | delete the word in front of the cursor |
| Ctrl + Shift + Right | ⌃⇧→ | delete the word after the cursor |
| Ctrl + Shift + Up | ⌃⇧↑ | delete the row in front of the cursor |
| Ctrl + Shift + Down | ⌃⇧↓ | delete the row after the cursor |
| Return | ⏎ | Confirm line entry |
| Backspace | ⌫ | delete one previous character from current position of cursor |
| Delete | ⌦ | delete one character from current position of cursor |
| Home | ⇱  | move cursor to the beginning of the line |
| End | ⇲  | move cursor to the end of the line |
| Tab | ⇥ | Auto compilation |
| Ctrl + R | ⌃R | Search history |
| Ctrl + A | ⌃A | work same as Home |
| Ctrl + E | ⌃E | work same as End |
| Ctrl + U | ⌃U | clear all characters in front the cursor |
| Ctrl + K | ⌃K | clear all characters after the cursor |
| Ctrl + G | ⌃G | clear all characters in line |
| Ctrl + H | ⌃H | Undo the last change |
| Ctrl + L | ⌃L | clear screen |

## Preview

![](https://thumbs.gfycat.com/MarvelousPositiveAmphiuma-size_restricted.gif)

### Preview output
```
➜  21sh git:(master) ./21sh
✓ (21sh) cd /tmp/test_dir/
✓ (test_dir) pwd
/tmp/test_dir
✓ (test_dir) env
TERM_SESSION_ID=w0t0p0:D3D7901C-F606-4245-89ED-C2B1F3E713F3
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.ldiuufG508/Listeners
LC_TERMINAL_VERSION=3.3.6
Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.lcd6sflWma/Render
COLORFGBG=7;0
ITERM_PROFILE=Default
XPC_FLAGS=0x0
PWD=/tmp/test_dir
SHELL=21sh
LC_CTYPE=UTF-8
TERM_PROGRAM_VERSION=3.3.6
TERM_PROGRAM=iTerm.app
PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/mysql/bin
LC_TERMINAL=iTerm2
COLORTERM=truecolor
TERM=xterm-256color
HOME=/Users/prippa
TMPDIR=/var/folders/nc/lc4x38yx18sgjmwh0qyy9prw0000gn/T/
USER=prippa
XPC_SERVICE_NAME=0
LOGNAME=prippa
ITERM_SESSION_ID=w0t0p0:D3D7901C-F606-4245-89ED-C2B1F3E713F3
__CF_USER_TEXT_ENCODING=0x0:7:49
SHLVL=2
OLDPWD=/Users/prippa/Desktop/21sh
LC_ALL=en_US.UTF-8
LANG=en_US.UTF-8
ZSH=/Users/prippa/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
_=env
✓ (test_dir) touch riri
✓ (test_dir) ls
riri
✓ (test_dir) rm riri ;cat riri 2>&-
✕ (test_dir) cat riri
cat: riri: No such file or directory
✕ (test_dir) mkdir test; cd test; ls -a; ls | cat | wc -c > fifi; cat fifi
.	..
       5
✓ (test) pwd
/tmp/test_dir/test
✓ (test) echo '
quote> Hello
quote> World
quote> !
quote> '; echo "awesome $SHELL";\
> exit

Hello
World
!

awesome 21sh
exit
➜  21sh git:(master)
```

[more info](https://github.com/prippa/21sh/blob/master/21sh.en.pdf)
