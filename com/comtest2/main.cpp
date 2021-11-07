#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include "../comdemo2/BeginningCOM.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);

	HRESULT hr = NULL;
	IUnknown* puk;

	hr = CoGetClassObject(CLSID_BeginningCOM, CLSCTX_INPROC_SERVER, NULL, IID_IUnknown, (void**)&puk);

	if (SUCCEEDED(hr))
	{
		//do nothing
		puk->Release();
	}
	else
	{
		cout << "Failed to create object" << endl;
	}

	CoUninitialize();

	return 0;
}