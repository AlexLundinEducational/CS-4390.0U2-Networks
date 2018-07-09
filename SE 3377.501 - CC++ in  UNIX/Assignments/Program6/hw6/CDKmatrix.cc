//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX
#include "program6.h"
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"


using namespace std;

// forward class definitions
class BinaryFileHeader;
class BinaryFileRecord;

// class definitions
class BinaryFileHeader
{
	public:
	uint32_t magicNumber; /* Should be 0xFEEDFACE */
	uint32_t versionNumber;
	uint64_t numRecords;
};


// Records in the file have a fixed length buffer
// that will hold a C-Style string. This is the
// size of the fixed length buffer.
const int maxRecordStringLength = 25;

class BinaryFileRecord
{
	public:
	uint8_t strLength;
	char stringBuffer[maxRecordStringLength];
};

// method prototypes
std::string itoa(uint64_t val, int base);

int main()
{

	// binary IO
	std::string binaryRecordFile = "./cs3377.bin";

	// read the header
	BinaryFileHeader *myHeader = new BinaryFileHeader();
	ifstream binInfile (binaryRecordFile.c_str(), ios::in | ios::binary);
	binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));	
	
	
	

	// CDK Screen Matrix
	WINDOW	*window;
	CDKSCREEN	*cdkscreen;
	CDKMATRIX     *myMatrix;           
	const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c", "d", "e"};
	const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c"};
	int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
	int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};



	// Initialize the Cdk screen.
	// Make sure the putty terminal is large enough
	window = initscr();
	cdkscreen = initCDKScreen(window);

	// Start CDK Colors
	initCDKColor();


	// Create the matrix.
	myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
	MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
	boxTypes, 1, 1, ' ', ROW, true, true, false);

	if (myMatrix ==NULL)
	{
		printf("Error creating Matrix\n");
		_exit(1);
	}

	// Display the Matrix
	drawCDKMatrix(myMatrix, true);

	
	// convert the magicNumber to string, which is a integer represenation of a hex number
	char buffHex[256];
	sprintf(buffHex, "Magic: 0x%-02X" , myHeader->magicNumber);

	// display magicNumber in matrix
	setCDKMatrixCell(myMatrix, 1, 1, buffHex);
	
	// convert the versionNumber to string, which is a integer represenation of a integer
	char buffInt[256];
	sprintf(buffInt, "Version: %-d" , myHeader->versionNumber);
	setCDKMatrixCell(myMatrix, 1, 2, buffInt);
	
	// convert the numRecord to string, which is a integer represenation of a integer
	char buffInt2[256];
	sprintf(buffInt2, "Num records: %-d" , myHeader->numRecords);
	setCDKMatrixCell(myMatrix, 1, 3, buffInt2);
	

	
	
	
	
	
	// loop based on number of records found in the header
	// add to matrix during loop
	const long RECORD_SIZE = sizeof(BinaryFileRecord);
	int j = 2;
	for (int i = 1; i <= (uint32_t)myHeader->numRecords ; i++){
		
		// reset j each iteration, j controls the column of data insertion into the matrix for this loop
		j = 1;
		
		// read a record from the binary file
		BinaryFileRecord *myRecord = new BinaryFileRecord();

		// ifstream binInfile (binaryRecordFile.c_str(), ios::in | ios::binary);

		binInfile.read((char *) myRecord, sizeof(BinaryFileRecord));
		
		// convert string length to string, which is a integer represenation
		char buff[30];
		sprintf(buff, "strlen: %d", myRecord->strLength);
	      
		char buff2[25];
		sprintf(buff2, "%s" , myRecord->stringBuffer);

		// only store the first 4 records to the matrix
		if(i <= 4 ){
	
		  setCDKMatrixCell(myMatrix, i + 1, j, buff);
		  j++;
		  setCDKMatrixCell(myMatrix, i + 1, j, buff2);
	     
		}
		delete myRecord;
		 
	}	
	
	
	
	
	// actually draw the matrix from values above
	drawCDKMatrix(myMatrix, true);

	// keep results on screen until user presses key
	cin.ignore();

	
	// Cleanup screen and close file
	endCDK();
	binInfile.close();

	
}



// integer to string method
std::string itoa(uint64_t value, int base) {
	
	//cout << "Itoa input was: " << setprecision(10) << value << endl;

	
	enum { kMaxDigits = 35 };
	
	std::string buf;
	
	buf.reserve( kMaxDigits ); // Pre-allocate enough space.
	

	
	// check that the base if valid
	
	if (base < 2 || base > 16) return buf;
	


	
	int quotient = value;
	

	
	// Translating number to string with base:
	
	do {
	
		buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
	
		quotient /= base;
	
	} while ( quotient );
	


	
	// Append the negative sign for base 10
	// if the value is less than 0
	if ( value < 0 && base == 10) buf += '-';
	

	
	std::reverse( buf.begin(), buf.end() );
	
	return buf;
	
}
