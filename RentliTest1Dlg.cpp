
// RentliTest1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "RentliTest1.h"
#include "RentliTest1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region MFC Default 



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRentliTest1Dlg dialog



CRentliTest1Dlg::CRentliTest1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RENTLITEST1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRentliTest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list1);
	//DDX_Text(pDX, IDC_NameBox, (CString)name.c_str());
	//DDX_Control(pDX, IDC_NumOfDays, IDC_NumOfDays);
}

BEGIN_MESSAGE_MAP(CRentliTest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRentliTest1Dlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CRentliTest1Dlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_NameBox, &CRentliTest1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRentliTest1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CRentliTest1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO1, &CRentliTest1Dlg::OnBnClickedRadio1)
	ON_CBN_SELCHANGE(IDC_VehiclesCombo, &CRentliTest1Dlg::OnCbnSelchangeVehiclescombo)
	//ON_EN_CHANGE(IDC_NumOfDays, &CRentliTest1Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON3, &CRentliTest1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRentliTest1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO2, &CRentliTest1Dlg::OnBnClickedRadio2)
	//ON_BN_CLICKED(IDC_BUTTON6, &CRentliTest1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CRentliTest1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_ButtonManage, &CRentliTest1Dlg::OnBnClickedButtonmanage)
	ON_BN_CLICKED(IDC_AddCarRadio, &CRentliTest1Dlg::OnBnClickedAddcarradio)
	ON_BN_CLICKED(IDC_InventoryOKButton, &CRentliTest1Dlg::OnBnClickedInventoryokbutton)
	ON_BN_CLICKED(IDC_EditCarRadio, &CRentliTest1Dlg::OnBnClickedEditcarradio)
	ON_CBN_SELCHANGE(IDC_InventoryCombo, &CRentliTest1Dlg::OnCbnSelchangeInventorycombo)
	ON_BN_CLICKED(IDC_deleteRadio, &CRentliTest1Dlg::OnBnClickeddeleteradio)
	ON_BN_CLICKED(IDC_CarManageBtn, &CRentliTest1Dlg::OnBnClickedCarmanagebtn)
	ON_BN_CLICKED(IDC_MotorManageBtn, &CRentliTest1Dlg::OnBnClickedMotormanagebtn)
	ON_BN_CLICKED(IDC_RentVehicleBtn, &CRentliTest1Dlg::OnBnClickedRentvehiclebtn)
	ON_BN_CLICKED(IDC_SaveButton, &CRentliTest1Dlg::OnBnClickedSavebutton)
	ON_BN_CLICKED(IDC_LoadButton, &CRentliTest1Dlg::OnBnClickedLoadbutton)
	ON_BN_CLICKED(IDC_InventoryCancelButton, &CRentliTest1Dlg::OnBnClickedInventorycancelbutton)
END_MESSAGE_MAP()


// CRentliTest1Dlg message handlers

BOOL CRentliTest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 380, 120, SWP_NOMOVE); // Set window size

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRentliTest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRentliTest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRentliTest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma endregion


#pragma region Utility Functions

void CRentliTest1Dlg::FillDefaultCars()
{
	Car* car1 = new Car(4, "Automatic", "Audi TT", 288, "Red", 230);
	Car* car2 = new Car(4, "Manual", "Subaru Impreza", 152, "White", 120);
	Car* car3 = new Car(4, "Automatic", "Mazda 3", 186, "White", 110);
	Car* car4 = new Car(4, "Automatic", "Tesla 3", 480, "Orange", 300);

	allCars.Add(&*car1);
	allCars.Add(&*car2);
	allCars.Add(&*car3);
	allCars.Add(&*car4);
}

void CRentliTest1Dlg::FillDefaultMotors()
{
	Motorcycle* motor1 = new Motorcycle("Automatic", "Suzuki V-Strom", 70, "Blue", 70);
	Motorcycle* motor2 = new Motorcycle("Manual", "Kawasaki Versys", 59, "Black", 50);
	Motorcycle* motor3 = new Motorcycle("Automatic", "Yamaha Super Tenere", 108, "Red", 100);
	Motorcycle* motor4 = new Motorcycle("Manual", "Ducati Multistrada", 150, "Yellow", 140);

	allMotors.Add(&*motor1);
	allMotors.Add(&*motor2);
	allMotors.Add(&*motor3);
	allMotors.Add(&*motor4);
}

void CRentliTest1Dlg::clearLists()
{
	int allCarsSize = allCars.GetSize();
	int allMotorsSize = allMotors.GetSize();

	for (int i = 0; i < allCarsSize; i++)
	{
		delete allCars[i];
	}

	allCars.RemoveAll();

	for (int i = 0; i < allMotorsSize; i++)
	{
		delete allMotors[i];
	}

	allMotors.RemoveAll();
}

#pragma endregion



void CRentliTest1Dlg::OnBnClickedButton1() // Rent Button
{
	MessageBox(CString("Thank You For The Purchase, by Rentli ©."), CString("Thank You!"));
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CRentliTest1Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CRentliTest1Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


#pragma region Rent A Vehicle


void CRentliTest1Dlg::OnBnClickedButton7() // Rent a vehicle button
{
	if (!cArraysFilled)
	{
		FillDefaultCars();
		FillDefaultMotors();
		cArraysFilled = 1; // to prevent duplications with filling arrays by "manage inventory" button.
	}

	int allCarsSize = allCars.GetSize();
	int allMotorsSize = allMotors.GetSize();

	if (allCars.IsEmpty() && allMotors.IsEmpty())
	{
		MessageBox(_T("We are out of stock! Come back later."), _T("Alert!"));
	}

	else if (!(allCars.IsEmpty()) && allMotors.IsEmpty())
	{
		MessageBox(_T("There are only cars available."), _T("Alert!"));
	}

	else if (!(allMotors.IsEmpty()) && allCars.IsEmpty())
	{
		MessageBox(_T("There are only motorcycles available."), _T("Alert!"));
	}

	else // all items available
	{
		GetDlgItem(IDC_ButtonManage)->EnableWindow(0); // disble manage inventory button
		GetDlgItem(horsePowerLabel)->ShowWindow(FALSE); // remove interference

		GetDlgItem(nameLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_NameBox)->ShowWindow(TRUE);
		GetDlgItem(ageLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_AgeBox)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);

		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 375, 270, SWP_NOMOVE);
	}
}


void CRentliTest1Dlg::OnBnClickedButton2() //  Submit Client Details
{
	// add if array is empty - pop a notification and disable radio button

	

	CEdit * nameEditBox = (CEdit*)GetDlgItem(IDC_NameBox);
	CEdit * ageEditBox = (CEdit*)GetDlgItem(IDC_AgeBox);
	nameEditBox->GetWindowTextW(cClientName);
	ageEditBox->GetWindowTextW(cAge);

	string nameString = CT2A(cClientName);
	int ageInt = _ttoi(cAge);

	if (nameString == "")
	{
		MessageBox(CString("Please Enter A Valid Name."), CString("Error!"));
	}

	if (ageInt < 18 || ageInt > 80)
	{
		MessageBox(CString("Age Must Be Between 18-80!"), CString("Error!"));
	}

	if(nameString != "" && (ageInt >= 18 && ageInt <= 80))
	{
		GetDlgItem(IDC_WelcomeLabel)->ShowWindow(TRUE);
		GetDlgItem(whatToRentLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO1)->ShowWindow(TRUE);
		GetDlgItem(IDC_VehiclesCombo)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(TRUE);
		GetDlgItem(ilsLabel)->ShowWindow(TRUE);
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 375, 390, SWP_NOMOVE);

		// Initialize Num of days to default value
		CEdit* numDays = (CEdit*)GetDlgItem(IDC_NumOfDays);
		CString numOfDaysString(to_string(cNumOfDays).c_str());
		numDays->SetWindowTextW(numOfDaysString);


		if (!cArraysFilled)
		{
			FillDefaultCars();
			FillDefaultMotors();
			GetDlgItem(IDC_BUTTON2)->EnableWindow(0); // disable Submit button after use 
			cArraysFilled = 1;
		}

		else GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	}
}


void CRentliTest1Dlg::OnBnClickedButton5() // View Details
{
	// Show name, age, car model, number of days and total payment
	list1.ResetContent();
	CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);
	int index = vehiclesCombo->GetCurSel();

	if(cCarRadio)
		CString displayModel(allCars[index]->getModel().c_str());

	else if(cMotorRadio)
		CString displayModel(allMotors[index]->getModel().c_str());

	CString displayNumDays(to_string(cNumOfDays).c_str());
	CString displayPayment(to_string(int(cTotalPayment)).c_str());

	CString format1, format2, format3, format4, format5;

	format1.Format(_T("Name: %s"), cClientName);
	format2.Format(_T("Age: %s"), cAge);

	if (cCarRadio) {
		CString displayModel(allCars[index]->getModel().c_str());
		format3.Format(_T("Model: %s"), displayModel);
	}

	else if (cMotorRadio) {
		CString displayModel(allMotors[index]->getModel().c_str());
		format3.Format(_T("Model: %s"), displayModel);
	}


	format4.Format(_T("Number Of Days: %s"), displayNumDays);
	format5.Format(_T("Total Payment: %s ILS"), displayPayment);

	list1.AddString(format1);
	list1.AddString(format2);
	list1.AddString(format3);
	list1.AddString(format4);
	list1.AddString(format5);
}

void CRentliTest1Dlg::OnBnClickedRadio1() // Cars Radio Button
{
	cCarRadio = 1;
	cMotorRadio = 0;
	CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);

	vehiclesCombo->ResetContent();
	//allCars.RemoveAll(); // reset array

	for (int i = 0; i < allCars.GetSize(); i++)
	{
		vehiclesCombo->AddString((CString)allCars[i]->getModel().c_str());
	}
	
	
	// Car(int numSeats, string gearBox, string model, int horsePower, string color, int price)
	/*Car car1(4, "Automatic", "Audi TT", 288, "Red", 230);
	Car car1(4, "Automatic", "Audi TT", 288, "Red", 230);*/
}


void CRentliTest1Dlg::OnBnClickedRadio2() // Motorcycle Radio Button
{
	cMotorRadio = 1;
	cCarRadio = 0;
	CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);

	vehiclesCombo->ResetContent();

	for (int i = 0; i < allMotors.GetSize(); i++)
	{
		vehiclesCombo->AddString((CString)allMotors[i]->getModel().c_str());
	}
}


void CRentliTest1Dlg::OnCbnSelchangeVehiclescombo() // Select vehicle from combo
{
	if (cCarRadio) // Car Radio is selected
	{
		list1.ResetContent();

		CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);
		int index = vehiclesCombo->GetCurSel();

		// If number of days > 0, change total payment regarding to the current car
		if (cNumOfDays > 0) {
			cTotalPayment = cNumOfDays * allCars[index]->getPrice();
			CEdit* totalBox = (CEdit*)GetDlgItem(IDC_TotalEditBox);
			CString totalString(to_string(cTotalPayment).c_str());
			totalBox->SetWindowTextW(totalString);
		}


		CString displayModel(allCars[index]->getModel().c_str()); // Model: Tesla 3
		CString displayColor(allCars[index]->getColor().c_str());
		CString displayGearBox(allCars[index]->getGearBox().c_str());
		CString displayHorsePower(to_string(allCars[index]->getHorsePower()).c_str());
		CString displayNumSeats(to_string(allCars[index]->getNumOfSeats()).c_str()); // using to_string() conversion
		CString displayPrice(to_string(int(allCars[index]->getPrice())).c_str());

		CString format1, format2, format3, format4, format5, format6;

		format1.Format(_T("Model: %s"), displayModel);
		format2.Format(_T("Color: %s"), displayColor);
		format3.Format(_T("Gearbox: %s"), displayGearBox);
		format4.Format(_T("HorsePower: %s"), displayHorsePower);
		format5.Format(_T("Num Of Seats: %s"), displayNumSeats);
		format6.Format(_T("Price: %s ILS"), displayPrice);

		list1.AddString(format1);
		list1.AddString(format2);
		list1.AddString(format3);
		list1.AddString(format4);
		list1.AddString(format5);
		list1.AddString(format6);
	}

	else if (cMotorRadio) // Motorcycle Radio is selected - the same code as above, adapted to motorcycle
	{
		list1.ResetContent();

		CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);
		int index = vehiclesCombo->GetCurSel();

		// If number of days > 0, change total payment regarding to the current car
		if (cNumOfDays > 0) {
			cTotalPayment = cNumOfDays * allMotors[index]->getPrice();
			CEdit* totalBox = (CEdit*)GetDlgItem(IDC_TotalEditBox);
			CString totalString(to_string(cTotalPayment).c_str());
			totalBox->SetWindowTextW(totalString);
		}


		CString displayModel(allMotors[index]->getModel().c_str()); // Model: Tesla 3
		CString displayColor(allMotors[index]->getColor().c_str());
		CString displayGearBox(allMotors[index]->getGearBox().c_str());
		CString displayHorsePower(to_string(allMotors[index]->getHorsePower()).c_str());
		CString displayPrice(to_string(allMotors[index]->getPrice()).c_str());

		CString format1, format2, format3, format4, format5;

		format1.Format(_T("Model: %s"), displayModel);
		format2.Format(_T("Color: %s"), displayColor);
		format3.Format(_T("Gearbox: %s"), displayGearBox);
		format4.Format(_T("HorsePower: %s"), displayHorsePower);
		format5.Format(_T("Price: %s"), displayPrice);

		list1.AddString(format1);
		list1.AddString(format2);
		list1.AddString(format3);
		list1.AddString(format4);
		list1.AddString(format5);
	}

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 375, 750, SWP_NOMOVE);
	GetDlgItem(detailsLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_LIST1)->ShowWindow(TRUE);
	GetDlgItem(numDaysLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	GetDlgItem(IDC_NumOfDays)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
	GetDlgItem(totalLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_TotalEditBox)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(TRUE);
}


void CRentliTest1Dlg::OnBnClickedButton3() // + days button
{
	CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);
	int index = vehiclesCombo->GetCurSel();

	if(cCarRadio)
		cTotalPayment += allCars[index]->getPrice();

	else if(cMotorRadio)
		cTotalPayment += allMotors[index]->getPrice();

	cNumOfDays++;
	// Change number of days
	CEdit* numDays = (CEdit*)GetDlgItem(IDC_NumOfDays);
	CString numOfDaysString(to_string(cNumOfDays).c_str());
	numDays->SetWindowTextW(numOfDaysString);

	// Change total payment
	CEdit* totalBox = (CEdit*)GetDlgItem(IDC_TotalEditBox); 
	CString totalString(to_string((int)cTotalPayment).c_str());
	totalBox->SetWindowTextW(totalString);
}


void CRentliTest1Dlg::OnBnClickedButton4() // - days button
{
	CComboBox* vehiclesCombo = (CComboBox*)GetDlgItem(IDC_VehiclesCombo);
	int index = vehiclesCombo->GetCurSel();


	if (cNumOfDays > 0)
	{
		if (cCarRadio)
			cTotalPayment -= allCars[index]->getPrice();

		else if(cMotorRadio)
			cTotalPayment -= allMotors[index]->getPrice();

		cNumOfDays--;

		// Change number of days
		CEdit* numDays = (CEdit*)GetDlgItem(IDC_NumOfDays);
		CString numOfDaysString(to_string(cNumOfDays).c_str());
		numDays->SetWindowTextW(numOfDaysString);

		// Change total payment
		CEdit* totalBox = (CEdit*)GetDlgItem(IDC_TotalEditBox);
		CString totalString(to_string(cTotalPayment).c_str());
		totalBox->SetWindowTextW(totalString);
	}
	// TODO: Add your control notification handler code here
}




#pragma endregion


#pragma region Manage Inventory


void CRentliTest1Dlg::OnBnClickedButtonmanage() // Manage inventory
{
	if (!cArraysFilled)
	{
		FillDefaultCars();
		FillDefaultMotors();
		cArraysFilled = 1;
	}

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 714, 115, SWP_NOMOVE); // Set window size

	UpdateData(TRUE);

	GetDlgItem(IDC_CarManageBtn)->ShowWindow(TRUE);
	GetDlgItem(IDC_MotorManageBtn)->ShowWindow(TRUE);

	UpdateData(FALSE);


}

void CRentliTest1Dlg::OnBnClickedCarmanagebtn() // Press on car manage button
{
	cCarManageSelected = 1;
	cMotorManageSelected = 0;

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 728, 160, SWP_NOMOVE); // Set window size

	UpdateData(TRUE);

	GetDlgItem(IDC_AddCarRadio)->ShowWindow(TRUE);
	GetDlgItem(IDC_deleteRadio)->ShowWindow(TRUE);
	GetDlgItem(IDC_EditCarRadio)->ShowWindow(TRUE);

	UpdateData(FALSE);
}

void CRentliTest1Dlg::OnBnClickedMotormanagebtn() // Press on motor manage button
{
	cMotorManageSelected = 1;
	cCarManageSelected = 0;

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 728, 160, SWP_NOMOVE); // Set window size

	UpdateData(TRUE);

	GetDlgItem(IDC_AddCarRadio)->ShowWindow(TRUE);
	GetDlgItem(IDC_deleteRadio)->ShowWindow(TRUE);
	GetDlgItem(IDC_EditCarRadio)->ShowWindow(TRUE);

	UpdateData(FALSE);
}



void CRentliTest1Dlg::OnBnClickedAddcarradio() // Add to invetory radio select button
{
	cAddVehicleRadio = 1;
	cEditVehicleRadio = 0;
	cDeleteVehicleRadio = 0;

	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 956, 287, SWP_NOMOVE); // Set window size

	UpdateData(TRUE);

	GetDlgItem(IDC_colorLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_colorEdit)->ShowWindow(TRUE);
	GetDlgItem(priceLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_priceEdit)->ShowWindow(TRUE);
	GetDlgItem(IDC_SaveButton)->ShowWindow(TRUE);
	GetDlgItem(IDC_InventoryOKButton)->ShowWindow(TRUE);
	GetDlgItem(modelLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_modelEdit)->ShowWindow(TRUE);
	GetDlgItem(gearBoxLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_gearBoxEdit)->ShowWindow(TRUE);
	GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
	GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);
	GetDlgItem(horsePowerLabel)->ShowWindow(TRUE);
	GetDlgItem(IDC_horsePowerEdit)->ShowWindow(TRUE);

	if (cCarManageSelected) 
	{
		GetDlgItem(numSeatsLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(TRUE);
	}

	else if (cMotorManageSelected) // Motor doesn't contain number of seats
	{
		GetDlgItem(numSeatsLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(FALSE);
	}

	GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
	GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);

	GetDlgItem(IDC_InventoryCombo)->ShowWindow(FALSE);

	UpdateData(FALSE);
}

void CRentliTest1Dlg::OnBnClickeddeleteradio() // Delete from inventory
{
	cDeleteVehicleRadio = 1;
	cEditVehicleRadio = 0;
	cAddVehicleRadio = 0;

	CComboBox* invCombo = (CComboBox*)GetDlgItem(IDC_InventoryCombo);
	invCombo->ResetContent();

	int allCarsSize = allCars.GetSize();
	int allMotorsSize = allMotors.GetSize();

	if (cCarManageSelected && allCarsSize > 0)
	{
		for (int i = 0; i < allCars.GetSize(); i++)
		{
			invCombo->AddString((CString)allCars[i]->getModel().c_str());
		}
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 957, 240, SWP_NOMOVE); // Set window size
		UpdateData(TRUE);

		GetDlgItem(IDC_InventoryCombo)->ShowWindow(TRUE);
		GetDlgItem(IDC_SaveButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryOKButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);

		GetDlgItem(IDC_colorLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_colorEdit)->ShowWindow(FALSE);
		GetDlgItem(priceLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_priceEdit)->ShowWindow(FALSE);
		GetDlgItem(modelLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_modelEdit)->ShowWindow(FALSE);
		GetDlgItem(gearBoxLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_gearBoxEdit)->ShowWindow(FALSE);
		GetDlgItem(horsePowerLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_horsePowerEdit)->ShowWindow(FALSE);
		GetDlgItem(numSeatsLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(FALSE);

		UpdateData(FALSE);
	}

	else if (cMotorManageSelected && allMotorsSize > 0)
	{
		for (int i = 0; i < allMotors.GetSize(); i++)
		{
			invCombo->AddString((CString)allMotors[i]->getModel().c_str());
		}
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 957, 240, SWP_NOMOVE); // Set window size

		UpdateData(TRUE);

		GetDlgItem(IDC_InventoryCombo)->ShowWindow(TRUE);
		GetDlgItem(IDC_SaveButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryOKButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);

		GetDlgItem(IDC_colorLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_colorEdit)->ShowWindow(FALSE);
		GetDlgItem(priceLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_priceEdit)->ShowWindow(FALSE);
		GetDlgItem(modelLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_modelEdit)->ShowWindow(FALSE);
		GetDlgItem(gearBoxLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_gearBoxEdit)->ShowWindow(FALSE);
		GetDlgItem(horsePowerLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_horsePowerEdit)->ShowWindow(FALSE);
		GetDlgItem(numSeatsLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(FALSE);

		UpdateData(FALSE);
	}

	else // No items to delete, reduces window size
	{
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 728, 160, SWP_NOMOVE); // Set window size
		MessageBox(_T("No Items To Delete!"), _T("Alert"));
	}
	// combo visible
}

void CRentliTest1Dlg::OnBnClickedEditcarradio() // Edit from inventory radio button
{
	cEditVehicleRadio = 1;
	cAddVehicleRadio = 0;
	cDeleteVehicleRadio = 0;

	CComboBox* invCombo = (CComboBox*)GetDlgItem(IDC_InventoryCombo);
	invCombo->ResetContent();

	int allCarsSize = allCars.GetSize();
	int allMotorsSize = allMotors.GetSize();

	if (cCarManageSelected && allCarsSize > 0)
	{
		for (int i = 0; i < allCars.GetSize(); i++)
		{
			invCombo->AddString((CString)allCars[i]->getModel().c_str());
		}
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 957, 240, SWP_NOMOVE); // Set window size

		UpdateData(TRUE);

		GetDlgItem(IDC_InventoryCombo)->ShowWindow(TRUE);
		GetDlgItem(IDC_SaveButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryOKButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_colorLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_colorEdit)->ShowWindow(TRUE);
		GetDlgItem(priceLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_priceEdit)->ShowWindow(TRUE);

		GetDlgItem(modelLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_modelEdit)->ShowWindow(FALSE);
		GetDlgItem(gearBoxLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_gearBoxEdit)->ShowWindow(FALSE);
		GetDlgItem(horsePowerLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_horsePowerEdit)->ShowWindow(FALSE);
		GetDlgItem(numSeatsLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(FALSE);

		UpdateData(FALSE);
	}

	else if (cMotorManageSelected && allMotorsSize > 0)
	{
		for (int i = 0; i < allMotors.GetSize(); i++)
		{
			invCombo->AddString((CString)allMotors[i]->getModel().c_str());
		}
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 957, 240, SWP_NOMOVE); // Set window size

		UpdateData(TRUE);

		GetDlgItem(IDC_InventoryCombo)->ShowWindow(TRUE);
		GetDlgItem(IDC_SaveButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryOKButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_LoadButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_InventoryCancelButton)->ShowWindow(TRUE);
		GetDlgItem(IDC_colorLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_colorEdit)->ShowWindow(TRUE);
		GetDlgItem(priceLabel)->ShowWindow(TRUE);
		GetDlgItem(IDC_priceEdit)->ShowWindow(TRUE);

		GetDlgItem(modelLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_modelEdit)->ShowWindow(FALSE);
		GetDlgItem(gearBoxLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_gearBoxEdit)->ShowWindow(FALSE);
		GetDlgItem(horsePowerLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_horsePowerEdit)->ShowWindow(FALSE);
		GetDlgItem(numSeatsLabel)->ShowWindow(FALSE);
		GetDlgItem(IDC_numOfSeatsEdit)->ShowWindow(FALSE);

		UpdateData(FALSE);
	}

	else // No items to edit, reduces window size
	{
		AfxGetMainWnd()->SetWindowPos(0, 0, 0, 728, 160, SWP_NOMOVE); // Set window size
		MessageBox(_T("No Items To Edit!"), _T("Alert"));
	}

	// combo visible
}

void CRentliTest1Dlg::OnBnClickedInventoryokbutton() // Click OK on inventory window
{
	if (cAddVehicleRadio) // add enabled
	{
		// car added notification

		CString numOfSeats, gearBox, model, horsePower, color, price;
			
		GetDlgItem(IDC_gearBoxEdit)->GetWindowTextW(gearBox);
		GetDlgItem(IDC_modelEdit)->GetWindowTextW(model);
		GetDlgItem(IDC_horsePowerEdit)->GetWindowTextW(horsePower);
		GetDlgItem(IDC_colorEdit)->GetWindowTextW(color);
		GetDlgItem(IDC_priceEdit)->GetWindowTextW(price);

		string gearBoxString = CT2A(gearBox); // CString to std::string conversion
		string modelString = CT2A(model);
		int horsePowerInt = _ttoi(horsePower); // CString to Int conversion
		string colorString = CT2A(color);
		int priceInt = _ttoi(price);

		if (cCarManageSelected)
		{
			CString gearBox;
			GetDlgItem(IDC_numOfSeatsEdit)->GetWindowTextW(numOfSeats);
			int numOfSeatsInt = _ttoi(numOfSeats); // CString to Int conversion
			Car* newCar = new Car(numOfSeatsInt, gearBoxString, modelString, horsePowerInt, colorString, priceInt);
			allCars.Add(&*newCar);
			MessageBox(_T("Car Added Successfully!"), _T("Success!"));
		}
		
		else if (cMotorManageSelected)
		{
			Motorcycle* newMotor = new Motorcycle(gearBoxString, modelString, horsePowerInt, colorString, priceInt);
			allMotors.Add(&*newMotor);
			MessageBox(_T("Motorcycle Added Successfully!"), _T("Success!"));
		}
		
	}

	else if (cDeleteVehicleRadio) // delete enabled
	{
		CComboBox* invCombo = (CComboBox*)GetDlgItem(IDC_InventoryCombo);
		int index = invCombo->GetCurSel();

		// car added notification

		int allCarsSize = allCars.GetSize();
		int allMotorsSize = allMotors.GetSize();


		if (cCarManageSelected && allCarsSize > 0) {
			allCars.RemoveAt(index, 1);
			OnBnClickeddeleteradio(); // to update combo box directly after pressing ok.
			MessageBox(_T("Deleted Successfully!"), _T("Success!"));
		}

		else if (cMotorManageSelected && allMotorsSize > 0) {
			allMotors.RemoveAt(index, 1);
			OnBnClickeddeleteradio(); // to update combo box directly after pressing ok.
			MessageBox(_T("Deleted Successfully!"), _T("Success!"));
		}
		
		else
			MessageBox(_T("No Items To Delete!"), _T("Alert"));
	}

	else if (cEditVehicleRadio) // edit enabled
	{
		CComboBox* invCombo = (CComboBox*)GetDlgItem(IDC_InventoryCombo);
		int index = invCombo->GetCurSel();

		// car edited notification

		int allCarsSize = allCars.GetSize();
		int allMotorsSize = allMotors.GetSize();

		CString color, price;

		GetDlgItem(IDC_colorEdit)->GetWindowTextW(color);
		GetDlgItem(IDC_priceEdit)->GetWindowTextW(price);

		string colorString = CT2A(color);
		int priceInt = _ttoi(price);

		if (cCarManageSelected && allCarsSize > 0)
		{
			allCars[index]->setColor(colorString);
			allCars[index]->setPrice(priceInt);
			OnBnClickedEditcarradio(); // to update combo box values after pressing ok.
			MessageBox(_T("Edited Successfully!"), _T("Success!"));
		}

		else if (cMotorManageSelected && allMotorsSize > 0)
		{
			allMotors[index]->setColor(colorString);
			allMotors[index]->setPrice(priceInt);
			OnBnClickedEditcarradio(); // to update combo box values after pressing ok.
			MessageBox(_T("Edited Successfully!"), _T("Success!"));
		}

		else
			MessageBox(_T("No Items To Edit!"), _T("Alert"));
	}
}


void CRentliTest1Dlg::OnBnClickedInventorycancelbutton()
{
	AfxGetMainWnd()->SetWindowPos(0, 0, 0, 380, 120, SWP_NOMOVE); // Set window size
}

void CRentliTest1Dlg::OnBnClickedSavebutton() // Save
{
	TCHAR szFilters[] = _T("Project Files(n.res)|n.res|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE, _T("res"), _T("order1.res"), OFN_HIDEREADONLY, szFilters);
	if (fileDlg.DoModal() == IDOK) {
		CFile file(fileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);

		allCars.Serialize(ar);
		allMotors.Serialize(ar);

		MessageBox(CString("Inventory Saved Successfully."), CString("Success!"));

		ar.Close();
		file.Close();
	}
}


void CRentliTest1Dlg::OnBnClickedLoadbutton() // Load
{
	TCHAR szFilters[] = _T("Project Files(n)|n.res|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE, _T("res"), _T("order1.res"), OFN_HIDEREADONLY, szFilters);
	if (fileDlg.DoModal() == IDOK)
	{
		CFile file(fileDlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);

		allCars.Serialize(ar);
		allMotors.Serialize(ar);

		MessageBox(CString("Inventory Loaded Successfully."), CString("Success!"));

		ar.Close();
		file.Close();
	}

	cArraysFilled = 1;
}



void CRentliTest1Dlg::OnCbnSelchangeInventorycombo() // Select item from inventory
{
	
}


#pragma endregion

void CRentliTest1Dlg::OnBnClickedRentvehiclebtn()
{
	// TODO: Add your control notification handler code here
}





