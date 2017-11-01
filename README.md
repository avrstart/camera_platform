# camera_platform
Qt gui control for moving platform with camera

Protocol description:

'*' - start byte
00-0xFFFF - cmd 2 bytes 
00-0xFFFF - data 2 bytes
'#' - end byte

cmd:
0 - test, return ok
1 - move camera up
2 - move camera down
3 - move camera right
4 - move camera left
5 - move camera to center

5 - camera increase speed 
6 - camera decrease speed 

10 - stop caterpillar all
11 - stop caterpillar left
12 - stop caterpillar right

13 - move left caterpillar forward
14 - move left caterpillar back

15 - move right caterpillar forward
16 - move right caterpillar back

20 - increase speed
21 - decrease speed
