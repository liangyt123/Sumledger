// Copyright (c) 2017 liang yuanting
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

extern bool RecvLine(SOCKET hSocket, string& strLine);
extern void ThreadIRCSeed(void* parg);
extern bool fRestartIRCSeed;
