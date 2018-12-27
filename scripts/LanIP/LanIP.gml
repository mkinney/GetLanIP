/* 
	LanIP - get non-looopback ip address
*/

if (os_type == os_windows) 
{
    var _result = external_call(external_define("MyLib.dll", "LanIP", dll_cdecl, ty_string, 0));
    external_free("MyLib.dll");
    return _result;
}

if (os_type == os_macosx)
{
    var _result = external_call(external_define("libMyLib.dylib", "LanIP", dll_cdecl, ty_string, 0));
    external_free("libMyLib.dylib");
    return _result;
}

if (os_type == os_linux) 
{
    var _result = external_call(external_define("libMyLib.so", "LanIP", dll_cdecl, ty_string, 0));
    external_free("libMyLib.so");
    return _result;
}