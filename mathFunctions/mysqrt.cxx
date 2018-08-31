// mysqrt.hpp
// Just a small change 
/*
#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

::vbo::victorvalentin.bordea@harman.com
::adi::Activity Diagram
::smdi::State Machine Diagram
::tru::[true]
::fls::[false]
::wlex::writeLineEx(1,1, "Error");
::ccomm::/** ************ `n`n ************ 
::lcomm:://* 
::ccline:://* ------------  ------------
::cout::std`:`:cout <<
::endl:: std`:`:endl;
::svec::std`:`:vector<>
::sthrd::std`:`:thread<>
::@remove::/* ** @Victor - remove line ** */
/*
::start-sh2::start f:\Inst\teraterm\ttermpro.exe /F=f:\Inst\teraterm\Hermes_SH2.INI
::start-nad::start f:\Inst\teraterm\ttermpro.exe /F=f:\Inst\teraterm\Hermes_NAD.INI
::start-wuc::start f:\Inst\teraterm\ttermpro.exe /F=f:\Inst\teraterm\Hermes_WUC.INI
::comit::git commit -m ""
::gstat::git status`n
*/

#include "mathFunctions.hpp"

#define EPSILON 1e-10

double mysqrt(double value){
#if defined (HAVE_LOG) && defined (HAVE_EXP)
	std::cout << "Platform has support for log and expo functions\n";
#else
	std::cout << "Platform does NOT have support for log and expo functions\n";
#endif
	if(value < 0)
	{
		std::cout << "Error in the input value. Negative input received." << std::endl;
		return -1;
	}
	double a = 1;
	double b = value;
	if(value < 1)
	{
		a = value;
		b = 1;
	}
	double mid = (a + b) / 2;
	double err = mid * mid - value;
	while(fabs(err) > EPSILON)
	{
		if(err > 0)
		{
			b = mid;
		}else{
			a = mid;
		}
		mid = (a + b) / 2;
		err = mid * mid - value;
	}
	return mid;
}