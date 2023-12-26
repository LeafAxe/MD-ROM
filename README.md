# MD-ROM (Minidisc Data Encoder/Decoder)
Adapt arbitrary files to be burn-ready for normal audio MiniDiscs.

WebMiniDisc Pro v1.4.0 added the ability to burn ATRAC files (.aea) directly to MiniDiscs, provided the user has a NetMD enabled burner.

This new homebrew feature allows for arbitrary data of any kind to be stored on an MD, without the need for the special Hi-MD models.

Note: This is not compatible with MD-Data discs/burners. This is designed for use with regular audio MiniDiscs to act like an MD-Data disc.

The goal of this program is to adapt an input file for burning onto an MD, as well as decoding a stored arbitrary file from an MD.

Encoding mechanism: 
1. An ATRAC file header is written
2. Two null bytes will be appended to the end of a group of 210 bytes from the original file (making it a group of 212 bytes). This ensures that the important data doesn't get corrupted, as it is those 2 unimportant bytes in every group that get corrupted.
3. Store transformed data in a .aea file
Note: if the number of bytes of the transformed data is not fully divisible by 212, null bytes will be added at the end of the file to ensure that it is.

Decoder mechanism:
1. Erases header
2. Erases the last 2 bytes of every 212 byte soundgroup
3. Stores decoded data in a .bin file
Note: In most cases, there will be extraneous null bytes at the end of the decoded file due to the extraneous bytes purposefully added in the encoding process. This can cause problems for some files, such as
zip files.

