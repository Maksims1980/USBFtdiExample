
// USBtestDlg.h : header file
//

#pragma once

#include "FTD2XX.H"



UINT ThreadProc1(LPVOID param);
const int ON = 100;
const int OFF = 101;


// CUSBtestDlg dialog
class CUSBtestDlg : public CDialogEx
{
// Construction
public:
	CUSBtestDlg(CWnd* pParent = nullptr);	// standard constructor
	void CUSBtestDlg::buttons(int onoff);
	void CUSBtestDlg::Loadem();
	FT_STATUS Write(LPVOID, DWORD, LPDWORD);
	FT_STATUS CUSBtestDlg::OpenBy();

	// Dialog Data
	//{{AFX_DATA(CUSBtestDlg)
	enum { IDD = IDD_USBTEST_DIALOG };
	CSliderCtrl	m_Slide;
	CListBox	m_Received;
	CString	m_PortStatus;
	CString	m_EchoRes;
	long	m_NumRecd;
	CString	m_128status;
	CString	m_NameNmbr;
	int		m_SerDesc;
	//}}AFX_DATA


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USBTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

// Implementation
protected:
	HICON m_hIcon;
	HMODULE m_hmodule;
	FT_HANDLE m_ftHandle;
	void LoadDLL();

	typedef FT_STATUS(WINAPI *PtrToOpen)(PVOID, FT_HANDLE *);
	PtrToOpen m_pOpen;
	FT_STATUS Open(PVOID);

	typedef FT_STATUS(WINAPI *PtrToOpenEx)(PVOID, DWORD, FT_HANDLE *);
	PtrToOpenEx m_pOpenEx;
	FT_STATUS OpenEx(PVOID, DWORD);

	typedef FT_STATUS(WINAPI *PtrToListDevices)(PVOID, PVOID, DWORD);
	PtrToListDevices m_pListDevices;
	FT_STATUS ListDevices(PVOID, PVOID, DWORD);

	typedef FT_STATUS(WINAPI *PtrToClose)(FT_HANDLE);
	PtrToClose m_pClose;
	FT_STATUS Close();

	typedef FT_STATUS(WINAPI *PtrToRead)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
	PtrToRead m_pRead;
	FT_STATUS Read(LPVOID, DWORD, LPDWORD);

	typedef FT_STATUS(WINAPI *PtrToWrite)(FT_HANDLE, LPVOID, DWORD, LPDWORD);
	PtrToWrite m_pWrite;
	//FT_STATUS Write(LPVOID, DWORD, LPDWORD);

	typedef FT_STATUS(WINAPI *PtrToResetDevice)(FT_HANDLE);
	PtrToResetDevice m_pResetDevice;
	FT_STATUS ResetDevice();

	typedef FT_STATUS(WINAPI *PtrToPurge)(FT_HANDLE, ULONG);
	PtrToPurge m_pPurge;
	FT_STATUS Purge(ULONG);

	typedef FT_STATUS(WINAPI *PtrToSetTimeouts)(FT_HANDLE, ULONG, ULONG);
	PtrToSetTimeouts m_pSetTimeouts;
	FT_STATUS SetTimeouts(ULONG, ULONG);

	typedef FT_STATUS(WINAPI *PtrToGetQueueStatus)(FT_HANDLE, LPDWORD);
	PtrToGetQueueStatus m_pGetQueueStatus;
	FT_STATUS GetQueueStatus(LPDWORD);



	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	virtual void OnOK();
	afx_msg void OnReleasedcaptureSliderWriteRate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonSend64Echo();
	afx_msg void OnButtonSendRecdis();
	afx_msg void OnButtonBlinkOn();
	afx_msg void OnButtonBlinkOff();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonClear();
	afx_msg void OnButtonHello();
	afx_msg void OnRadioNameNum();
	afx_msg void OnRadioSernum();
	afx_msg void OnChangeEditNameNumber();
	afx_msg void OnRadioDevno();
	afx_msg void OnButtonSearch();
	afx_msg void OnSelchangeList1();

	DECLARE_MESSAGE_MAP()
};
