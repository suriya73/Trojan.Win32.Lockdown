/*
	@title
		AHXRScreenLock
	@author
		AHXR (https://github.com/AHXR)
	@copyright
		2017

	AHXRScreenLock is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AHXRScreenLock is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AHXRScreenLock.  If not, see <http://www.gnu.org/licenses/>.

	https://msdn.microsoft.com/en-us/library/windows/desktop/ms737889(v=vs.85).aspx
*/
//=======================================================
#include				<Windows.h>
#include				"server_manage.h"

HANDLE					h_server;
DWORD					dw_server;
bool					b_server_status;
bool					b_accepting;

bool startServer() {

	if (b_server_status)
		return false;

	h_server = CreateThread(0, 0, t_serverProcess, 0, 0, &dw_server);
	return true;
}

bool isServerAccepting() {
	return b_accepting;
}

bool stopServer() {
	if (!b_server_status)
		return false;

	CloseHandle(h_server);
	b_server_status = false;
	return true;
}