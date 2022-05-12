//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include "Word_2K_SRVR.h"
#include <OleServer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edtC_Id;
        TButton *BtnNext;
        TADOConnection *Conn;
        TADODataSet *customer;
        TButton *BtnFrist;
        TEdit *edtC_Name;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *edtC_Sex;
        TLabel *Label4;
        TEdit *edtC_Tel;
        TButton *BtnPrior;
        TButton *BtnChange;
        TButton *BtnDelete;
        TButton *BtnAdd;
        TListView *ListView1;
        TLabel *Label5;
        TButton *BtnList;
        TButton *BtnEnd;
        TButton *BtnExit;
        TButton *BtnSelect;
        void __fastcall BtnFristClick(TObject *Sender);
        void __fastcall BtnNextClick(TObject *Sender);
        void __fastcall BtnPriorClick(TObject *Sender);
        void __fastcall BtnChangeClick(TObject *Sender);
        void __fastcall BtnDeleteClick(TObject *Sender);
        void __fastcall BtnAddClick(TObject *Sender);
        void __fastcall BtnListClick(TObject *Sender);
        void __fastcall BtnEndClick(TObject *Sender);
        void __fastcall BtnSelectClick(TObject *Sender);
        void __fastcall BtnExitClick(TObject *Sender);
private:	// User declarations
        void ShowData();
        void ListTitleCreat();
        void ListDataShow();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ListView1MouseDown(TComponent* Owner, TMouseButton Button);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 