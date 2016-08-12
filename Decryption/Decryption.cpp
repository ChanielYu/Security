/*
 * Decryption.cpp
 *
 *  Created on: 11Aug.,2016
 *      Author: chanielyu
 */

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <iomanip>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "Decryption.h"

using namespace std;

static int appError;

int main(int argc, const char* argv[])
{
	const char *inFile, *outFile;
	appError = 0;
	cout << "Application started..." << endl;
	if (argc < 3)
	{
		cout << "Too few parameters!" << endl;
		cout << "Application exit with error code=" << GetAppErrorCode()
				<< endl;
		return GetAppErrorCode();
	}
	else
	{
		inFile = argv[1];
		outFile = argv[2];
	}
	string command("openssl aes-256-cbc -k \"nBnC0#PaSsWoRd0\" -in ");
	command.append(inFile);
	command.append(" -d -a -out ");
	command.append(outFile);
	const char* cmd = command.c_str();
	//cout<<cmd<<endl;
	cout<<"Decrypting..."<<endl;
	system(command.c_str());
	cout << "Application exit with error code=" << GetAppErrorCode() << endl;
	return GetAppErrorCode();
}

int GetAppErrorCode()
{
	return appError;
}

void SetAppErrorCode(int errorCode)
{
	appError = errorCode;
}
