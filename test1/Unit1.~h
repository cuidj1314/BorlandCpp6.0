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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edtC_Id;
        TButton *BtnNext;
        TADOConnection *Conn;
        TADODataSet *customer;
        TButton *BtnList;
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
        void __fastcall BtnListClick(TObject *Sender);
        void __fastcall BtnNextClick(TObject *Sender);
        void __fastcall BtnPriorClick(TObject *Sender);
        void __fastcall BtnChangeClick(TObject *Sender);
        void __fastcall BtnDeleteClick(TObject *Sender);
        void __fastcall BtnAddClick(TObject *Sender);
private:	// User declarations
        void ShowData();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 