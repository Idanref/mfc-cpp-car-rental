#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
// RentliTest1Dlg.h : header file
//

#pragma once


// CRentliTest1Dlg dialog
class CRentliTest1Dlg : public CDialogEx
{
// Construction
public:
	CRentliTest1Dlg(CWnd* pParent = nullptr);	// standard constructor
	// add initialize values to dlg object
	~CRentliTest1Dlg() { clearLists(); }

	CTypedPtrArray <CObArray, Car*> allCars;
	CTypedPtrArray <CObArray, Motorcycle*> allMotors;

	void FillDefaultCars();
	void FillDefaultMotors();
	void clearLists();
	
private:
	CString cClientName;
	CString cAge;
	int cNumOfDays = 0;
	int cCarRadio = 0;
	int cMotorRadio = 0;
	double cTotalPayment = 0;
	int cArraysFilled = 0;

	// Manage Inventory Section
	int cCarManageSelected = 0;
	int cMotorManageSelected = 0;
	int cAddVehicleRadio = 0;
	int cEditVehicleRadio = 0;
	int cDeleteVehicleRadio = 0;
	


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENTLITEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox list1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
	//string name;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnCbnSelchangeVehiclescombo();

	
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton3();
	//CEdit IDC_NumOfDays;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButtonmanage();
	afx_msg void OnBnClickedAddcarradio();
	afx_msg void OnBnClickedInventoryokbutton();
	afx_msg void OnBnClickedEditcarradio();
	afx_msg void OnCbnSelchangeInventorycombo();
	afx_msg void OnBnClickeddeleteradio();
	afx_msg void OnBnClickedCarmanagebtn();
	afx_msg void OnBnClickedMotormanagebtn();
	afx_msg void OnBnClickedRentvehiclebtn();
	afx_msg void OnBnClickedSavebutton();
	afx_msg void OnBnClickedLoadbutton();
	afx_msg void OnBnClickedInventorycancelbutton();
};
