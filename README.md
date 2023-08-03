# ATRAC-ROM
Adapt arbitrary files to be burn-ready for normal audio MiniDiscs.

WebMiniDisc Pro v1.4.0 added the ability to burn ATRAC files (.aea) directly to MiniDiscs, provided the user has a NetMD enabled burner.

This new homebrew feature allows for arbitrary data of any kind to be stored on an MD, without the need for the special Hi-MD model(s) that can already do so more easily. One can inject data into an existing .aea file using a hex editor, overwriting the sound data.

There is a catch, however. 

The last 2 out of every 212 bytes of the 'sound' data get corrupted, and nothing more. It is unclear if the corruption occurs on the burning or the ripping of the track, nor is it clear whether it is the fault of the player, WebMiniDisc, or both.

Nonetheless, the goal of this program is to adapt an input file for burning onto an MD by working around those very consistent discrepancies.
The adaptation also corrupts the file, but it does so losslessly. Therefore, the program also comes with a decoder which can undo the encoding.

As of writing, this program is in a very alpha state and is more a proof of concept more than anything else. 
It doesn't generate an ATRAC file or modify one. In fact, it doesn't have anything to do with ATRAC. It simply adapts a file which can later be manually injected into an ATRAC file using a hex editor.

Steps for encoding:
1. Gather file of interest and the executable in one folder.
2. Open the program.
3. Enter 'E'.
4. Enter in the exact number of bytes of the input file.
5. Enter in the filename with the file extension.
6. A file named 'newfile.bin' will be generated, and this is the adapted file.

Steps for decoding:
1. Gather adapted file and executable in one folder.
2. Open the program.
3. Enter 'D'.
4. Enter in the exact number of bytes of the adapted file.
5. Enter in the filename with the file extension.
6. A file named 'decod.bin' will be generated, which functions as the original file before the encoding adaptation.
