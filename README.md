# Wing Master Lab(WML) : A dynamic taskwarrior - based task controller

This is a terminal tools that can manage your life.

## install
Normally:
```bash
$ git clone https://github.com/AMIRIOX/wml.git
```
If your location is China or other users who have problems accessing github:
```bash
$ git clone https://github.com.cnpmjs.org/AMIRIOX/wml.git
```
Then
```bash
$ make install # you should modify makefile before
```

## use
Show version: _$ wml --version_     
Task interface: _$ wml add pri:H pro:life cook-breakfast #See 'man task'_    
Show status:     
```bash
$ wml --status # or wml -s
```
Change value:
```bash
$ wml -c 10 # add global contribution, you shouldn't use it most of the time
$ wml -d 10 # add today's contribution, change global contribution,too
$ wml -t -10 # change tiring value
$ # after working a day, remember:
$ wml --refresh # use -r is also allowed.
```

## demo
> waiting for more
