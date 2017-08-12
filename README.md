# Calculator
Simple Console Calculator using C++


# ClassMap

- Node Class diagram, include Number Node, Operator node(Binary Node, UnaryNode and Multiple Node) and variable node.
<p>
<img src="class diagram/class1.png"  width="90%" />
</p>

- Scanner class is responsible for the expression of the scan, Parser class is parse the expression to the corresponding node.
<p>
<img src="class diagram/class2.png" width="80%" />
</p>

- These classes are mainly responsible for the storage of data, including the function and variable. Serialize class nmake the storage of data can serialize
<p>
<img src="class diagram/class3.png" width="80%" />
</p>

# How to use
### Recogniaed Commands
- !h: Help
- !quit: quit
- !v: show variable list
- !f: show funcation list
- !load filename: load file
- !save filename: save variable and funcation to file

### Example
```
>> 123+7-10*8-10+9*(4-3)/4
42.25
>>-10*7+4-10
-76
>>a=4
4
>>b=3
3
>>a+b-3*5/3
2
>>e*10/2
13.5914
>>cos(100)*10-sqrt(4)
6.62319
>>!f
fucation list:
log
log10
exp
sqrt
sin
cos
tan
sinh
cosh
tanh
asin
acos
atan
>>e
2.71828
>>pi
3.14159
>>a
4
>>b
3
>>!save test.txt
save "test.txt".
>>!load test.txt
load "test.txt".
>>!quit
```

## Liense

```
Copyright 2016 henryblue

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
