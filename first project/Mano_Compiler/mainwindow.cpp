#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFileDialog>
#include<QFile>
#include<QString>
#include<QDataStream>
#include<QTextStream>

int global_pc_int;
int AC_int,AR_int,PC_int=0,org_int=0;
QString AC_hex,DR,IR="0",TR="0",AR_hex,PC_hex,INPR="0",OUTR="0",E="0",SC="0",I="0",Address_hex,Opcode_hex,SIGN="0";
int flag_org=0,flag_end=0,flag_hlt=0;
bool ok5;
 QHash<QString, QString>hashMAdressOpcode;
 QHash<QString, QString>hashMAdressInstruction;
 QHash<QString, QString>hashmAR;//M[AR]
 QHash<QString, int>hashLableltoHalgheshomar;//get label and go you to itrate with counter halgheshomar
 QHash<QString, int>hashNameoflabeltonumberofitsline;//hash name of label to addres line of it in QWidget table
 //QHash<QString, int>hashTurnOfLabelinLoop;//hash name of label to number of turn in loop
 QHash<QString, QString>hashNameoflabeltoAddress;
  QHash<QString, QString>hashAddresstoHex;

 int co_pc=0;

int flag_labelandinstruct=0;
int flag_labelandinstruct_compiler=0;
int co_address;
int flag_meory_compile=1;
int flag_memory=1;

 QHash<QString, QString> hashMemoryReferenceDirect;
 QHash<QString, QString> hashMemoryReferenceInDirect;
 QString and_m="AND",add_m="ADD",lda_m="LDA",sta_m="STA",bun_m="BUN",bsa_m="BSA",isz_m="ISZ";
// QString and_mi="AND I",add_mi="ADD I",lda_mi="LDA I",sta_mi="STA I",bun_mi="BUN I",bsa_mi="BSA I",isz_mi="ISZ I";
 QString zero="0",one="1",two="2",three="3",four="4",five="5",six="6",seven="7",eight="8";
 QString nine="9",ten="A",eleven="B",twoelve="C",therteen="D",fourteen="E",fifteen="F";

 QHash<QString, QString> hashRegisterRefrence;
 QString cla_r="CLA",cle_r="CLE",cma_r="CMA",cme_r="CME",cir_r="CIR";
 QString cil_r="CIL",inc_r="INC",spa_r="SPA",sna_r="SNA",sza_r="SZA",sze_r="SZE",hlt_r="HLT";



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   /* ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(4096);*/
    QString counterr;
    for(int ii=1;ii<4097;ii++)
    {
        counterr.setNum(ii-1,16);
        int lcounterr=counterr.length();
        if(lcounterr==1)
        {
            counterr="00"+counterr;
        }
        else if(lcounterr==2)
        {
            counterr="0"+counterr;
        }
        counterr=counterr.toUpper();
        ui->tableWidget->setItem(ii,1,new QTableWidgetItem(counterr));
        ui->tableWidget->setItem(ii,3,new QTableWidgetItem("000"));
    }



      //  hashMemoryReferenceDirect              hashMemoryReferenceInDirect
    hashMemoryReferenceDirect[and_m]=zero;    hashMemoryReferenceInDirect[and_m]=eight;

    hashMemoryReferenceDirect[add_m]=one;    hashMemoryReferenceInDirect[add_m]=nine;

    hashMemoryReferenceDirect[lda_m]=two;    hashMemoryReferenceInDirect[lda_m]=ten;

    hashMemoryReferenceDirect[sta_m]=three;    hashMemoryReferenceInDirect[sta_m]=eleven;

    hashMemoryReferenceDirect[bun_m]=four;    hashMemoryReferenceInDirect[bun_m]=twoelve;

    hashMemoryReferenceDirect[bsa_m]=five;    hashMemoryReferenceInDirect[bsa_m]=therteen;

    hashMemoryReferenceDirect[isz_m]=six;    hashMemoryReferenceInDirect[isz_m]=fourteen;

    hashRegisterRefrence[cla_r]="7800"; hashRegisterRefrence[cle_r]="7400"; hashRegisterRefrence[cma_r]="7200";
     hashRegisterRefrence[cme_r]="7100"; hashRegisterRefrence[cir_r]="7080"; hashRegisterRefrence[cil_r]="7040";
      hashRegisterRefrence[inc_r]="7020"; hashRegisterRefrence[spa_r]="7010"; hashRegisterRefrence[sna_r]="7008";
       hashRegisterRefrence[sza_r]="7004"; hashRegisterRefrence[sze_r]="7002"; hashRegisterRefrence[hlt_r]="7001";


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionReset_triggered()
{
    ui->ted_code->setText(NULL);



     global_pc_int=0;
     AC_int=0,AR_int=0,PC_int=0,org_int=0;
     AC_hex=nullptr;DR=nullptr;
     IR="0";
     TR="0";
     AR_hex=nullptr;
     PC_hex=nullptr;
     INPR="0";
     OUTR="0";
     E="0";
     SC="0";
     I="0";
     Address_hex=nullptr;
     Opcode_hex=nullptr;
     SIGN="0";
    flag_org=0,flag_end=0,flag_hlt=0;


     co_pc=0;

    flag_labelandinstruct=0;
    flag_labelandinstruct_compiler=0;
    co_address=0;
    flag_meory_compile=1;
    flag_memory=1;


    ui->lbl_AC->setText(NULL);
    ui->lbl_AR->setText(NULL);
    ui->lbl_DR->setText(NULL);
    ui->lbl_E->setText(NULL);
    ui->lbl_FGI->setText(NULL);
    ui->lbl_FGO->setText(NULL);
    ui->lbl_I->setText(NULL);
    ui->lbl_IEN->setText(NULL);
    ui->lbl_INPR->setText(NULL);
    ui->lbl_IR->setText(NULL);
    ui->lbl_OPCODE->setText(NULL);
    ui->lbl_OUTR->setText(NULL);
    ui->lbl_PC->setText(NULL);
    ui->lbl_SC->setText(NULL);
    ui->lbl_SIGN->setText(NULL);
    ui->lbl_TR->setText(NULL);
    ui->ted_code->setText(NULL);

    QString counterr;
    for(int ii=1;ii<4097;ii++)
    {
        counterr.setNum(ii-1,16);
        int lcounterr=counterr.length();
        if(lcounterr==1)
        {
            counterr="00"+counterr;
        }
        else if(lcounterr==2)
        {
            counterr="0"+counterr;
        }
        counterr=counterr.toUpper();
        ui->tableWidget->setItem(ii,1,new QTableWidgetItem(counterr));
        ui->tableWidget->setItem(ii,3,new QTableWidgetItem("000"));
        ui->tableWidget->setItem(ii,0,new QTableWidgetItem(NULL));
        ui->tableWidget->setItem(ii,2,new QTableWidgetItem(NULL));


    }




}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_me_triggered()
{
    QMessageBox::information(this,"About Me","Pasha Ahmadi");
}

void MainWindow::on_actionSave_2_triggered()
{
   /* QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Your Code"), "",
           tr("Code pasha (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
           return;
       else {
           QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly)) {



               QMessageBox::information(this, tr("Unable to open file"),
                   file.errorString());
               return;
           }
           QDataStream out(&file);
           QString ss=ui->ted_code->toPlainText();
              // out.setVersion(QDataStream::Qt_4_5);
               out <<QString(ss);
           }*/

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "", tr("Code pasha (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
            return;
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QTextStream out (&file);

        out << ui->ted_code->toPlainText();


        QFileInfo FileData(file);

        /*int currentTab = ui->tabWidget->currentIndex();
        ui->tabWidget->removeTab(currentTab);
        QTextStream InputData(&file);
        ui->tabWidget->insertTab(currentTab, new Form(), FileData.fileName());
        ui->tabWidget->setCurrentIndex(currentTab);
        ui->plainTextEdit->setPlainText(InputData.readAll());*/

        file.flush();
        file.close();
    }

}


void MainWindow::on_actionCompile_triggered()
{

    QHash<QString, int> hashVariables_int;
     QHash<QString, QString> hashVariables_hex;


     //PRE COMPILE_START
    /*************************************************************************************************************************/




    int co_pc_compile=0;
     QStringList sl1_compile=(ui->ted_code->toPlainText()).split('\n');

             foreach (QString item, sl1_compile)
             {

                 co_pc_compile++;
                 QStringList sl2_compile=item.split(' ');/*********************************/
                 int l=sl2_compile.length();

                 QString an_compile=sl2_compile.join(' ');
                 if(an_compile.contains(",") && l==2 && !an_compile.contains("HEX") && !an_compile.contains("DEC") )// to check wether we have instruction that has a label
                     flag_labelandinstruct_compiler=1;


                    if(l==1)
                    {
                        flag_meory_compile=0;//becauseof one length it means a register reference;
                    }
                    else
                    {
                        flag_meory_compile=1;
                    }

                 if(sl2_compile[0]=="ORG")
                 {
                     flag_org=1;
                     PC_hex=sl2_compile[1];
                    // ui->lbl_PC->setText(PC_hex);
                     PC_int=PC_hex.toInt(&ok5,16);
                     global_pc_int=PC_int;
                     co_pc_compile=PC_int-1;
                     org_int=PC_int;
                     QString co_org_hex;
                     int icount=0;

                     foreach (QString ijk, sl1_compile)
                     {
                         co_org_hex.setNum((org_int-1+icount),16);
                         hashMAdressInstruction[co_org_hex]=ijk;
                         icount++;
                     }

                 }
                else if (flag_meory_compile)
                {
                 if(sl2_compile[0]=="AND" || sl2_compile[0]=="ADD" || sl2_compile[0]=="LDA" || sl2_compile[0]=="STA" || sl2_compile[0]=="BUN" || sl2_compile[0]=="BSA" || sl2_compile[0]=="ISZ" || sl2_compile[1]=="AND" || sl2_compile[1]=="ADD" || sl2_compile[1]=="LDA" || sl2_compile[1]=="STA" || sl2_compile[1]=="BUN" || sl2_compile[1]=="BSA" || sl2_compile[1]=="ISZ")
                 {
                     int ssp_compile;
                     if(sl2_compile[0]=="AND" || sl2_compile[0]=="ADD" || sl2_compile[0]=="LDA" || sl2_compile[0]=="STA" || sl2_compile[0]=="BUN" || sl2_compile[0]=="BSA" || sl2_compile[0]=="ISZ")
                         ssp_compile=1;
                     else
                         ssp_compile=2;



                     if(sl2_compile[l-1]=="I")/**********************************************************/
                     {
                         I="1";


                         QString name_var=sl2_compile[ssp_compile];


                         int co_pc_compile2=org_int-1;
                         if(flag_org)
                             co_pc_compile2--;
                         foreach (QString item2, sl1_compile)
                         {
                             co_pc_compile2++;
                             QStringList sl3=item2.split(' ');

                             QString first_sl3=sl3[0];
                             first_sl3.remove(",");




                             if(first_sl3==name_var)
                             {


                                 Address_hex.setNum(co_pc_compile,16);
                                 AR_hex=Address_hex;
                                 Opcode_hex.setNum(co_pc_compile2,16);
                                  Opcode_hex=hashMemoryReferenceDirect[sl2_compile[ssp_compile-1]]+ Opcode_hex;
                                  ui->lbl_AR->setText(AR_hex);
                                  ui->lbl_OPCODE->setText(Opcode_hex);
                                   ui->tableWidget->setItem(co_pc_compile+1,3,new QTableWidgetItem(Opcode_hex));




                                // hashMAdressOpcode[]
                                 int number;
                                 if(sl3[1]=="HEX")
                                 {
                                      hashVariables_hex[name_var]=sl3[2];
                                     //number=hexToDec(sl3[2]);
                                     bool ok1;
                                     number=sl3[2].toInt(&ok1,16);

                                 }
                                 else if(sl3[1]=="DEC")
                                 {

                                    bool ok1;

                                    number=sl3[2].toInt(&ok1);
                                    if(number<0)
                                    {
                                        number=65536+number;
                                    }
                                 }
                                 if(sl3[1]=="DEC" || sl3[1]=="HEX")
                                 {
                                     QString numberhex1;
                                     numberhex1.setNum(number,16);
                                     hashVariables_int[name_var]=number;
                                     ui->tableWidget->setItem(co_pc_compile2+1,3,new QTableWidgetItem(numberhex1));
                                 }



                                // break;

                             }



                         }




                         if(sl2_compile[ssp_compile-1]=="AND")
                         {
                             DR.setNum(hashVariables_int[name_var],16);
                             AC_int=AC_int&hashVariables_int[name_var];
                             AC_hex.setNum(AC_int,16);



                             SC="5";
                             PC_int++;
                             PC_hex.setNum(PC_int,16);


                         }
                         else if(sl2_compile[ssp_compile-1]=="ADD")
                         {
                             SC="5";
                             DR.setNum(hashVariables_int[name_var],16);

                             AC_int=AC_int+hashVariables_int[name_var];
                             if(AC_int>=65536)
                             {
                                  AC_int=AC_int-65536;
                                  E="1";
                             }

                              AC_hex.setNum(AC_int,16);
                              /*ui->lbl_E->setText(E);
                              ui->lbl_AC->setText(AC_hex);*/


                              PC_int++;
                              PC_hex.setNum(PC_int,16);





                         }
                         else if(sl2_compile[ssp_compile-1]=="LDA")
                         {
                              DR.setNum(hashVariables_int[name_var],16);
                             AC_int=hashVariables_int[name_var];
                             AC_hex.setNum(AC_int,16);
                             SC="5";
                             //ui->lbl_PC->setText(PC_hex);

                             PC_int++;
                             PC_hex.setNum(PC_int,16);

                         }
                         else if(sl2_compile[ssp_compile-1]=="STA")
                         {
                             SC="4";
                             hashmAR[AR_hex]=AC_hex;
                             hashVariables_int[name_var]=AC_int;
                             hashVariables_hex[name_var]=AC_hex;

                             PC_int++;
                             PC_hex.setNum(PC_int,16);

                         }
                         else if(sl2_compile[ssp_compile-1]=="BUN")
                         {
                             SC=4;
                             PC_hex=AR_hex;

                             //item=hashMAdressInstruction[PC_hex];/********************************/
                         }
                         else if(sl2_compile[ssp_compile-1]=="BSA")
                         {

                         }
                         else if(sl2_compile[ssp_compile-1]=="ISZ")
                         {

                         }

                         // //////////////////////////
                         ui->lbl_AC->setText(AC_hex);
                         ui->lbl_PC->setText(PC_hex);
                         ui->lbl_AR->setText(AR_hex);
                         ui->lbl_E->setText(E);
                         ui->lbl_OPCODE->setText(Opcode_hex);
                         ui->lbl_DR->setText(DR);
                         ui->lbl_SC->setText(SC);

                         ui->lbl_SIGN->setText(SIGN);
                         ui->lbl_OUTR->setText(OUTR);
                         ui->lbl_INPR->setText(INPR);
                         ui->lbl_IEN->setText("0");
                         ui->lbl_FGI->setText("0");
                         ui->lbl_FGO->setText("0");
                         ui->lbl_I->setText(I);












                     }
                     else
                     {
                         QString name_var=sl2_compile[ssp_compile];


                         int co_pc_compile2=org_int-1;
                         if(flag_org)
                             co_pc_compile2--;
                         foreach (QString item2, sl1_compile)
                         {
                             co_pc_compile2++;
                             QStringList sl3=item2.split(' ');

                             QString first_sl3=sl3[0];
                             first_sl3.remove(",");




                             if(first_sl3==name_var)
                             {


                                 Address_hex.setNum(co_pc_compile,16);
                                 AR_hex=Address_hex;
                                 Opcode_hex.setNum(co_pc_compile2,16);
                                  Opcode_hex=hashMemoryReferenceDirect[sl2_compile[ssp_compile-1]]+ Opcode_hex;
                                  ui->lbl_AR->setText(AR_hex);
                                  ui->lbl_OPCODE->setText(Opcode_hex);
                                   ui->tableWidget->setItem(co_pc_compile+1,3,new QTableWidgetItem(Opcode_hex));




                                // hashMAdressOpcode[]
                                 int number;
                                 if(sl3[1]=="HEX")
                                 {
                                      hashVariables_hex[name_var]=sl3[2];
                                     //number=hexToDec(sl3[2]);
                                     bool ok1;
                                     number=sl3[2].toInt(&ok1,16);

                                 }
                                 else if(sl3[1]=="DEC")
                                 {

                                    bool ok1;

                                    number=sl3[2].toInt(&ok1);
                                    if(number<0)
                                    {
                                        number=65536+number;
                                    }
                                 }
                                 if(sl3[1]=="DEC" || sl3[1]=="HEX")
                                 {
                                     QString numberhex1;
                                     numberhex1.setNum(number,16);
                                     hashVariables_int[name_var]=number;
                                     ui->tableWidget->setItem(co_pc_compile2+1,3,new QTableWidgetItem(numberhex1));
                                 }



                                // break;

                             }



                         }




                         if(sl2_compile[ssp_compile-1]=="AND")
                         {
                             DR.setNum(hashVariables_int[name_var],16);
                             AC_int=AC_int&hashVariables_int[name_var];
                             AC_hex.setNum(AC_int,16);



                             SC="5";
                             PC_int++;
                             PC_hex.setNum(PC_int,16);


                         }
                         else if(sl2_compile[ssp_compile-1]=="ADD")
                         {
                             SC="5";
                             DR.setNum(hashVariables_int[name_var],16);

                             AC_int=AC_int+hashVariables_int[name_var];
                             if(AC_int>=65536)
                             {
                                  AC_int=AC_int-65536;
                                  E="1";
                             }

                              AC_hex.setNum(AC_int,16);
                              /*ui->lbl_E->setText(E);
                              ui->lbl_AC->setText(AC_hex);*/


                              PC_int++;
                              PC_hex.setNum(PC_int,16);





                         }
                         else if(sl2_compile[ssp_compile-1]=="LDA")
                         {
                              DR.setNum(hashVariables_int[name_var],16);
                             AC_int=hashVariables_int[name_var];
                             AC_hex.setNum(AC_int,16);
                             SC="5";
                             //ui->lbl_PC->setText(PC_hex);

                             PC_int++;
                             PC_hex.setNum(PC_int,16);

                         }
                         else if(sl2_compile[ssp_compile-1]=="STA")
                         {
                             SC="4";
                             hashmAR[AR_hex]=AC_hex;
                             hashVariables_int[name_var]=AC_int;
                             hashVariables_hex[name_var]=AC_hex;

                             PC_int++;
                             PC_hex.setNum(PC_int,16);

                         }
                         else if(sl2_compile[ssp_compile-1]=="BUN")
                         {
                             SC=4;
                             PC_hex=AR_hex;

                             //item=hashMAdressInstruction[PC_hex];/********************************/
                         }
                         else if(sl2_compile[ssp_compile-1]=="BSA")
                         {

                         }
                         else if(sl2_compile[ssp_compile-1]=="ISZ")
                         {

                         }

                         // //////////////////////////
                         ui->lbl_AC->setText(AC_hex);
                         ui->lbl_PC->setText(PC_hex);
                         ui->lbl_AR->setText(AR_hex);
                         ui->lbl_E->setText(E);
                         ui->lbl_OPCODE->setText(Opcode_hex);
                         ui->lbl_DR->setText(DR);
                         ui->lbl_SC->setText(SC);

                         ui->lbl_SIGN->setText(SIGN);
                         ui->lbl_OUTR->setText(OUTR);
                         ui->lbl_INPR->setText(INPR);
                         ui->lbl_IEN->setText("0");
                         ui->lbl_FGI->setText("0");
                         ui->lbl_FGO->setText("0");
                         ui->lbl_I->setText(I);




                     }
                 }}
                 else if( sl2_compile[0]=="CLA" || sl2_compile[0]=="CLE" || sl2_compile[0]=="CMA" || sl2_compile[0]=="CME" || sl2_compile[0]=="CIR" || sl2_compile[0]=="CIL" || sl2_compile[0]=="INC" || sl2_compile[0]=="SPA" || sl2_compile[0]=="SNA" || sl2_compile[0]=="SZA" || sl2_compile[0]=="SZE" || sl2_compile[0]=="HLT" || flag_labelandinstruct_compiler==1  )
                 {

                    int ssp_compile;

                     if(sl2_compile[0]=="CLA" || sl2_compile[0]=="CLE" || sl2_compile[0]=="CMA" || sl2_compile[0]=="CME" || sl2_compile[0]=="CIR" || sl2_compile[0]=="CIL" || sl2_compile[0]=="INC" || sl2_compile[0]=="SPA" || sl2_compile[0]=="SNA" || sl2_compile[0]=="SZA" || sl2_compile[0]=="SZE" || sl2_compile[0]=="HLT")
                         ssp_compile=1;
                     else
                     {
                          ssp_compile=2;
                          flag_labelandinstruct_compiler=0;
                     }







                     I="0";

                     if(sl2_compile[ssp_compile-1]=="CLA")
                     {

                         PC_int++;
                         PC_hex.setNum(PC_int,16);

                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

                     }
                     else if(sl2_compile[ssp_compile-1]=="CLE")
                     {

                         PC_int++;
                         PC_hex.setNum(PC_int,16);
                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

                     }
                    else if(sl2_compile[ssp_compile-1]=="CMA")
                     {


                        PC_int++;
                        PC_hex.setNum(PC_int,16);
                        IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                        ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


                     }
                     else if(sl2_compile[ssp_compile-1]=="CME")
                     {


                         PC_int++;
                         PC_hex.setNum(PC_int,16);
                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

                     }
                     else if(sl2_compile[ssp_compile-1]=="CIR")
                     {



                         PC_int++;
                         PC_hex.setNum(PC_int,16);
                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


                     }
                     else if(sl2_compile[ssp_compile-1]=="CIL")
                     {

                          PC_int++;
                          PC_hex.setNum(PC_int,16);
                          IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                          ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));



                     }
                     else if(sl2_compile[ssp_compile-1]=="INC")
                     {



                         PC_int++;
                         PC_hex.setNum(PC_int,16);
                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


                     }
                     else if(sl2_compile[ssp_compile-1]=="SPA")
                     {
                         qint16 co_AC_int=AC_int;

                         if(co_AC_int>0)
                         {
                             SIGN="0";
                             PC_int++;
                             int co_pc_compile_int33=PC_int+1;
                             QString co_pc_compile_hex33;
                             co_pc_compile_hex33.setNum(co_pc_compile_int33,16);
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                             ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


                         }
                         else
                         {


                             PC_int++;
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];

                         }


                     }
                     else if(sl2_compile[ssp_compile-1]=="SNA")
                     {

                         qint16 co_AC_int=AC_int;

                         if(co_AC_int<0)
                         {
                             SIGN="1";
                             PC_int++;
                             int co_pc_compile_int33=PC_int+1;
                             QString co_pc_compile_hex33;
                             co_pc_compile_hex33.setNum(co_pc_compile_int33,16);
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                             ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


                         }
                         else
                         {


                             PC_int++;
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];

                         }




                     }
                     else if(sl2_compile[ssp_compile-1]=="SZA")
                     {


                         if(AC_int>=65536)
                             AC_int=AC_int-65536;
                         if(AC_int==0)
                         {
                             PC_int++;
                             int co_pc_compile_int33=PC_int+1;
                             QString co_pc_compile_hex33;
                             co_pc_compile_hex33.setNum(co_pc_compile_int33,16);
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                             ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                         }
                         else
                         {
                             PC_int++;
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         }

                     }
                     else if(sl2_compile[ssp_compile-1]=="SZE")
                     {


                         if(E=="0")
                         {

                             PC_int++;
                             int co_pc_compile_int33=PC_int+1;
                             QString co_pc_compile_hex33;
                             co_pc_compile_hex33.setNum(co_pc_compile_int33,16);
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                             ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                         }
                         else
                         {
                             PC_int++;
                             PC_hex.setNum(PC_int,16);
                             IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         }

                     }
                     else if(sl2_compile[ssp_compile-1]=="HLT")
                     {

                        //QString scanter;
                        // scanter.setNum(canter);
                        // ui->lbl_IEN->setText(scanter);


                         flag_hlt=1;

                         PC_int++;
                         PC_hex.setNum(PC_int,16);
                         IR=hashRegisterRefrence[sl2_compile[ssp_compile-1]];
                         ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

                     }






                     // ///////////////////////////////////////
                     ui->lbl_AC->setText(AC_hex);
                     ui->lbl_PC->setText(PC_hex);
                     ui->lbl_AR->setText(AR_hex);
                     ui->lbl_E->setText(E);
                     ui->lbl_OPCODE->setText(Opcode_hex);
                     ui->lbl_DR->setText(DR);
                     ui->lbl_SC->setText(SC);
                     ui->lbl_IR->setText(IR);
                     ui->lbl_TR->setText(TR);
                      ui->lbl_SIGN->setText(SIGN);
                      ui->lbl_OUTR->setText(OUTR);
                      ui->lbl_INPR->setText(INPR);
                      ui->lbl_IEN->setText("0");
                      ui->lbl_FGI->setText("0");
                      ui->lbl_FGO->setText("0");
                      ui->lbl_I->setText(I);




                 }





             }
            /* int kl=sl1_compile.length();
             int line=PC_hex.toInt(&ok5,16)-1;
             for(int i=line;line<kl+line;i++)
             {
                 QTableWidgetItem* ad=ui->tableWidget->item(i,1);
                 QString ad_s;
                 QString he_s;
                 ad_s=ad->text();
                 QTableWidgetItem* he=ui->tableWidget->item(i,3);
                 he_s=he->text();
                 hashAddresstoHex[ad_s]=he_s;
                 if(i==line)
                  ui->lbl_var->setText(he_s);

             }*/

             //ui->lbl_var->setText(PC_hex);
            // hashAddresstoHex[]

            int line=PC_hex.toInt(&ok5,16)-1;








             //RESET PARAMETERS

             AC_int,AR_int,PC_int=0,org_int=0;
             AC_hex,DR,IR="0",TR="0",AR_hex,PC_hex,INPR="0",OUTR="0",E="0",SC="0",I="0",Address_hex,Opcode_hex,SIGN="0";
             flag_org=0,flag_end=0,flag_hlt=0;




     /************************************************************************************************************************/
       //PRE COMILE_END




      QStringList sl0=(ui->ted_code->toPlainText()).split('\n');
     int itable=0;QString address="0";int address1_int=0;
     int halgheshomar=0;
     foreach (QString var, sl0)
     {
         halgheshomar++;


         QStringList sl00=var.split(' ');

          /*ui->tableWidget->setItem(itable+1,0,new QTableWidgetItem(var));
          ui->tableWidget->setItem(itable+1,2,new QTableWidgetItem(sl00[1]));
          itable++;*/

         if(sl00[0]=="ORG")
         {
             address=sl00[1];
             itable=address.toInt(&ok5,16);
                co_address=address.toInt(&ok5,16);
             itable++;
             flag_org=1;
             continue;
         }
         int lll=sl00[0].length();
         if(sl00[0][lll-1]==",")
         {
              address1_int=co_address+halgheshomar-2;
             QString haz;
             haz=sl00[0];
             hashLableltoHalgheshomar[haz]=halgheshomar-1;
             QString haz3=haz;
             QString address1_hex;
             address1_hex.setNum(address1_int,16);
             hashNameoflabeltoAddress[haz3.remove(",")]=address1_hex;
             QString haz2=haz;
             hashNameoflabeltonumberofitsline[haz2.remove(",")]=itable;
                ui->tableWidget->setItem(itable,0,new QTableWidgetItem(haz.remove(",")));
               // ui->tableWidget->setItem(itable,0,new QTableWidgetItem(sl00[0]));
                QString inst=sl00.join(' ');
                ui->tableWidget->setItem(itable,2,new QTableWidgetItem(inst.remove(sl00[0])));
         }
         else
         {
             if(var!="END")
              ui->tableWidget->setItem(itable,2,new QTableWidgetItem(var));
         }
        itable++;
       // address1_int++;

     }




     int canter=0;//just for count number of itrates of below loop
        //int co_pc3;
    QStringList sl1=(ui->ted_code->toPlainText()).split('\n');

        int l_sl1=sl1.length();
    /*foreach (QString item, sl1)*/
    for(int ipg=0;ipg<l_sl1;ipg++)
    {
        canter++;

        co_pc=global_pc_int-1+ipg;
        //co_pc++;
        QStringList sl2=sl1[ipg].split(' ');/*********************************/
        int l=sl2.length();

        QString an=sl2.join(' ');
        if(an.contains(",") && l==2 && !an.contains("HEX") && !an.contains("DEC"))// to check wether we have instruction that has a label
            flag_labelandinstruct=1;

        if(l==1)
        {
            flag_memory=0;//becauseof one length it means a register reference;
        }
        else
        {
            flag_memory=1;
        }


        if(sl2[0]=="ORG")
        {
            flag_org=1;
            PC_hex=sl2[1];
           // ui->lbl_PC->setText(PC_hex);
            PC_int=PC_hex.toInt(&ok5,16);
            co_pc=PC_int-1;
            org_int=PC_int;
            QString co_org_hex;
            int icount=0;

            foreach (QString ijk, sl1)
            {
                co_org_hex.setNum((org_int-1+icount),16);
                hashMAdressInstruction[co_org_hex]=ijk;
                icount++;
            }

        }
       else if(flag_memory)
       {
          if(sl2[0]=="AND" || sl2[0]=="ADD" || sl2[0]=="LDA" || sl2[0]=="STA" || sl2[0]=="BUN" || sl2[0]=="BSA" || sl2[0]=="ISZ" ||  sl2[1]=="AND" || sl2[1]=="ADD" || sl2[1]=="LDA" || sl2[1]=="STA" || sl2[1]=="BUN" || sl2[1]=="BSA" || sl2[1]=="ISZ")
        {
            int ssp;
             if(sl2[0]=="AND" || sl2[0]=="ADD" || sl2[0]=="LDA" || sl2[0]=="STA" || sl2[0]=="BUN" || sl2[0]=="BSA" || sl2[0]=="ISZ")
                 ssp=1;
             else
                 ssp=2;

            if(sl2[l-1]=="I")
            {
                I="1";










            }
            else
            {
                QString name_var=sl2[ssp];

                int co_pc3=co_pc;
                int co_pc2=org_int-1;
                if(flag_org)
                    co_pc2--;
                foreach (QString item2, sl1)
                {
                    co_pc2++;
                    QStringList sl3=item2.split(' ');

                    QString first_sl3=sl3[0];
                    first_sl3.remove(",");




                    if(first_sl3==name_var)
                    {


                        Address_hex.setNum(co_pc3,16);
                        AR_hex=Address_hex;
                        Opcode_hex.setNum(co_pc2,16);
                         Opcode_hex=hashMemoryReferenceDirect[sl2[ssp-1]]+ Opcode_hex;
                         ui->lbl_AR->setText(AR_hex);
                         ui->lbl_OPCODE->setText(Opcode_hex);

                          ui->tableWidget->setItem(co_pc3+1,3,new QTableWidgetItem(Opcode_hex));




                       // hashMAdressOpcode[]
                        int number;
                        if(sl3[1]=="HEX")
                        {
                             hashVariables_hex[name_var]=sl3[2];
                            //number=hexToDec(sl3[2]);
                            bool ok1;
                            number=sl3[2].toInt(&ok1,16);

                        }
                        else if(sl3[1]=="DEC")
                        {

                           bool ok1;

                           number=sl3[2].toInt(&ok1);

                           if(number<0)
                           {
                               number=65536+number;
                           }

                        }
                      if(sl3[1]=="DEC" || sl3[1]=="HEX")
                      {
                          QString numberhex1;
                          numberhex1.setNum(number,16);
                          hashVariables_int[name_var]=number;
                          ui->tableWidget->setItem(co_pc2+1,3,new QTableWidgetItem(numberhex1));

                      }

                       // break;

                    }



                }




                if(sl2[ssp-1]=="AND")
                {
                    DR.setNum(hashVariables_int[name_var],16);
                    AC_int=AC_int&hashVariables_int[name_var];
                    AC_hex.setNum(AC_int,16);



                    SC="5";
                    PC_int++;
                    PC_hex.setNum(PC_int,16);


                }
                else if(sl2[ssp-1]=="ADD")
                {
                    SC="5";
                    DR.setNum(hashVariables_int[name_var],16);

                    AC_int=AC_int+hashVariables_int[name_var];
                    if(AC_int>=65536)
                    {
                         AC_int=AC_int-65536;
                         E="1";
                    }

                     AC_hex.setNum(AC_int,16);
                     /*ui->lbl_E->setText(E);
                     ui->lbl_AC->setText(AC_hex);*/


                     PC_int++;
                     PC_hex.setNum(PC_int,16);





                }
                else if(sl2[ssp-1]=="LDA")
                {
                     DR.setNum(hashVariables_int[name_var],16);
                    AC_int=hashVariables_int[name_var];
                    AC_hex.setNum(AC_int,16);
                    SC="5";
                    //ui->lbl_PC->setText(PC_hex);

                    PC_int++;
                    PC_hex.setNum(PC_int,16);

                }
                else if(sl2[ssp-1]=="STA")
                {
                    SC="4";
                    hashmAR[AR_hex]=AC_hex;
                    hashVariables_int[name_var]=AC_int;
                    hashVariables_hex[name_var]=AC_hex;

                    ui->tableWidget->setItem(hashNameoflabeltonumberofitsline[name_var],3,new QTableWidgetItem(AC_hex));

                    PC_int++;
                    PC_hex.setNum(PC_int,16);

                }
                else if(sl2[ssp-1]=="BUN")
                {
                    SC="4";
                    AR_hex=hashNameoflabeltoAddress[sl2[ssp]];
                    PC_hex=AR_hex;
                    PC_int=PC_hex.toInt(&ok5,16);
                    /*QString oop;
                    oop.setNum(co_pc2,16);
                    oop=hashMemoryReferenceDirect[sl2[ssp-1]]+oop;*/
                    //ui->tableWidget->setItem(global_pc_int+ipg,3,new QTableWidgetItem(oop));
                    //co_pc=PC_int-1;
                    /*QString karl;
                    karl.setNum(pppq);
                    ui->lbl_var->setText(karl);*/
                    ipg= hashLableltoHalgheshomar[name_var+","]-1;//because after this turn ipg also ++

                    //item=hashMAdressInstruction[PC_hex];/********************************/
                }
                else if(sl2[ssp-1]=="BSA")
                {

                }
                else if(sl2[ssp-1]=="ISZ")
                {
                    SC="6";
                    hashVariables_int[sl2[ssp]]+=1;
                    hashVariables_hex[sl2[ssp]].setNum(hashVariables_int[sl2[ssp]],16);
                    int co_dr=DR.toInt(&ok5,16);
                    co_dr++;
                    DR.setNum(co_dr,16);

                  ui->tableWidget->setItem(hashNameoflabeltonumberofitsline[sl2[ssp]],3,new QTableWidgetItem(hashVariables_hex[sl2[ssp]]));
                  if( hashVariables_int[sl2[ssp]]==0)
                  {
                      PC_int++;
                      int co_pc_int33=PC_int+1;
                      QString co_pc_hex33;
                      co_pc_hex33.setNum(co_pc_int33,16);
                      PC_hex.setNum(PC_int,16);
                      IR=hashRegisterRefrence[sl2[ssp-1]];
                      ipg++;// It means skip form nex loop


                    // QString ppc;

                     // ppc.setNum(PC_int);
                      // ui->lbl_var->setText(hashMAdressInstruction[co_pc_hex33]);
                      // ui->lbl_IEN->setText(co_pc_hex33);

                      //item=hashMAdressInstruction[co_pc_hex33];
                      global_pc_int++;
                      PC_int++;
                      PC_hex.setNum(PC_int,16);

                  }
                  else
                  {
                      PC_int++;
                      PC_hex.setNum(PC_int,16);

                  }


                }

                // //////////////////////////
                ui->lbl_AC->setText(AC_hex);
                ui->lbl_PC->setText(PC_hex);
                ui->lbl_AR->setText(AR_hex);
                ui->lbl_E->setText(E);
                ui->lbl_OPCODE->setText(Opcode_hex);
                ui->lbl_DR->setText(DR);
                ui->lbl_SC->setText(SC);
                ui->lbl_SIGN->setText(SIGN);
                ui->lbl_OUTR->setText(OUTR);
                ui->lbl_INPR->setText(INPR);
                ui->lbl_IEN->setText("0");
                ui->lbl_FGI->setText("0");
                ui->lbl_FGO->setText("0");
                ui->lbl_I->setText(I);




            }
        }}
        else if(sl2[0]=="CLA" || sl2[0]=="CLE" || sl2[0]=="CMA" || sl2[0]=="CME" || sl2[0]=="CIR" || sl2[0]=="CIL" || sl2[0]=="INC" || sl2[0]=="SPA" || sl2[0]=="SNA" || sl2[0]=="SZA" || sl2[0]=="SZE" || sl2[0]=="HLT" || flag_labelandinstruct==1 /*sl2[1]=="CLA" || sl2[1]=="CLE" || sl2[1]=="CMA" || sl2[1]=="CME" || sl2[1]=="CIR" || sl2[1]=="CIL" || sl2[1]=="INC" || sl2[1]=="SPA" || sl2[1]=="SNA" || sl2[1]=="SZA" || sl2[1]=="SZE" || sl2[1]=="HLT"*/ )
        {
            int ssp;
            if(sl2[0]=="CLA" || sl2[0]=="CLE" || sl2[0]=="CMA" || sl2[0]=="CME" || sl2[0]=="CIR" || sl2[0]=="CIL" || sl2[0]=="INC" || sl2[0]=="SPA" || sl2[0]=="SNA" || sl2[0]=="SZA" || sl2[0]=="SZE" || sl2[0]=="HLT")
                ssp=1;
            else
            {
                 ssp=2;
                 flag_labelandinstruct=0;
            }








            I="0";

            if(sl2[ssp-1]=="CLA")
            {
                AC_int=0;
                AC_hex="0";
                PC_int++;
                PC_hex.setNum(PC_int,16);

                IR=hashRegisterRefrence[sl2[ssp-1]];
                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

            }
            else if(sl2[ssp-1]=="CLE")
            {
                E="0";
                PC_int++;
                PC_hex.setNum(PC_int,16);
                IR=hashRegisterRefrence[sl2[ssp-1]];

                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

            }
            else if(sl2[ssp-1]=="CMA")
            {

                if(AC_int>=65536)
                    AC_int-=65536;


                AC_int=65536-AC_int-1;//beacuse we want one's complement and no 2's complement


               AC_hex.setNum(AC_int,16);

               
               PC_int++;
               PC_hex.setNum(PC_int,16);
               IR=hashRegisterRefrence[sl2[ssp-1]];
               ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


            }
            else if(sl2[ssp-1]=="CME")
            {
                if(E=="0")
                    E="1";
                else
                    E="0";

                PC_int++;
                PC_hex.setNum(PC_int,16);
                IR=hashRegisterRefrence[sl2[ssp-1]];
                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

            }
            else if(sl2[ssp-1]=="CIR")
            {


                if(AC_int>=65536)
                    AC_int=AC_int-65536;

                 qint16 co_AC_int=AC_int;

                if(AC_int%2==0)
                {
                    co_AC_int=co_AC_int/2;
                   AC_int=co_AC_int;
                   if(E=="1")
                   {
                       AC_int+=32768;
                   }

                   E="0";
                }
                else
                {
                   co_AC_int=co_AC_int-1;
                   co_AC_int=co_AC_int/2;
                    AC_int=co_AC_int;
                   if(E=="1")
                   {
                   AC_int=AC_int+32768;

                   }


                    E="1";

                }
                if(AC_int>=65536)
                    AC_int-=65536;

                AC_hex.setNum(AC_int,16);

                PC_int++;
                PC_hex.setNum(PC_int,16);
                IR=hashRegisterRefrence[sl2[ssp-1]];
                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


            }
            else if(sl2[ssp-1]=="CIL")
            {

                if(AC_int>=65536)
                    AC_int=AC_int-65536;




                 if(AC_int>=32768)
                 {
                     AC_int=AC_int*2;
                     if(E=="1")
                     {
                         AC_int+=1;
                     }

                     E="1";
                 }
                 else
                 {
                     AC_int=AC_int*2;
                     if(E=="1")
                     {
                         AC_int+=1;
                     }

                     E="0";
                 }

                 if(AC_int>=65536)
                     AC_int-=65536;

                 AC_hex.setNum(AC_int,16);

                 PC_int++;
                 PC_hex.setNum(PC_int,16);
                 IR=hashRegisterRefrence[sl2[ssp-1]];
                 ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));



            }
            else if(sl2[ssp-1]=="INC")
            {

                AC_int++;
                if(AC_int>=65536)
                    AC_int=AC_int-65536;

                AC_hex.setNum(AC_int,16);

                PC_int++;
                PC_hex.setNum(PC_int,16);
                IR=hashRegisterRefrence[sl2[ssp-1]];
                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));


            }
            else if(sl2[ssp-1]=="SPA")
            {
                qint16 co_AC_int=AC_int;

                if(co_AC_int>0)
                {
                    SIGN="0";
                    PC_int++;
                    int co_pc_int33=PC_int+1;
                    QString co_pc_hex33;
                    co_pc_hex33.setNum(co_pc_int33,16);
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];
                    ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                    ipg++;// It means skip form nex loop


                  // QString ppc;

                   // ppc.setNum(PC_int);
                    // ui->lbl_var->setText(hashMAdressInstruction[co_pc_hex33]);
                    // ui->lbl_IEN->setText(co_pc_hex33);

                    //item=hashMAdressInstruction[co_pc_hex33];
                    global_pc_int++;
                    PC_int++;
                    PC_hex.setNum(PC_int,16);

                }
                else
                {


                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];

                }


            }
            else if(sl2[ssp-1]=="SNA")
            {

                qint16 co_AC_int=AC_int;

                if(co_AC_int<0)
                {
                    SIGN="1";
                    PC_int++;
                    int co_pc_int33=PC_int+1;
                    QString co_pc_hex33;
                    co_pc_hex33.setNum(co_pc_int33,16);
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];
                    ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                    ipg++;// It means skip form nex loop
                    global_pc_int++;

                    PC_int++;
                    PC_hex.setNum(PC_int,16);

                }
                else
                {


                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];

                }




            }
            else if(sl2[ssp-1]=="SZA")
            {
                if(AC_int>=65536)
                    AC_int=AC_int-65536;

                if(AC_int==0)
                {
                    PC_int++;
                    int co_pc_int33=PC_int+1;
                    QString co_pc_hex33;
                    co_pc_hex33.setNum(co_pc_int33,16);
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];
                    ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                    ipg++;// It means skip form nex loop

                    global_pc_int++;

                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                }
                else
                {

                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];


                }




            }
            else if(sl2[ssp-1]=="SZE")
            {

                if(E=="0")
                {
                    PC_int++;
                    int co_pc_int33=PC_int+1;
                    QString co_pc_hex33;
                    co_pc_hex33.setNum(co_pc_int33,16);
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];
                    ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));
                    ipg++;// It means skip form nex loop

                    global_pc_int++;

                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                }
                else
                {

                    PC_int++;
                    PC_hex.setNum(PC_int,16);
                    IR=hashRegisterRefrence[sl2[ssp-1]];


                }


            }
           else if(sl2[ssp-1]=="HLT")
            {



                flag_hlt=1;

                PC_int++;
                PC_hex.setNum(PC_int,16);
                IR=hashRegisterRefrence[sl2[ssp-1]];
                ui->tableWidget->setItem(PC_int,3,new QTableWidgetItem(IR));

            }






            // ///////////////////////////////////////
            ui->lbl_AC->setText(AC_hex);
            ui->lbl_PC->setText(PC_hex);
            ui->lbl_AR->setText(AR_hex);
            ui->lbl_E->setText(E);
            ui->lbl_OPCODE->setText(Opcode_hex);
            ui->lbl_DR->setText(DR);
            ui->lbl_SC->setText(SC);
            ui->lbl_IR->setText(IR);
            ui->lbl_TR->setText(TR);
             ui->lbl_SIGN->setText(SIGN);
             ui->lbl_OUTR->setText(OUTR);
             ui->lbl_INPR->setText(INPR);
             ui->lbl_IEN->setText("0");
             ui->lbl_FGI->setText("0");
             ui->lbl_FGO->setText("0");
             ui->lbl_I->setText(I);









        }





    }

}



QString hexToBin(QString hexnum)
{
    QString binnum;

    foreach (QString i, hexnum)
        {
                 if(i== "0")
                   binnum+="0000";

                else if(i=="1")
                    binnum+="0001";

                else if(i=="2")
                    binnum+="0010";

                else if(i=="3")
                    binnum+="0011";

                else if(i=="4")
                    binnum+="0100";

                else if(i=="5")
                    binnum+="0101";

                else if(i=="6")
                    binnum+="0110";

                else if(i=="7")
                    binnum+="0111";

                else if(i=="8")
                    binnum+="1000";

                else if(i== "9")
                    binnum+="1001";

                else if(i=="A" || i=="a")
                    binnum+="1010";

                else if(i== "B" || i=="b")
                    binnum+="1011";

                else if(i== "C" || i=='c')
                    binnum+="1100";

                else if(i== "D" || i=="d")
                    binnum+="1101";

                else if(i== "E" || i=="e")
                    binnum+="1110";

                else if(i== "F" ||i== "f")
                    binnum+="1111";

        }

    return binnum;

}

int hexToDec(QString hexnum)
{
    bool ok; int appId = hexnum.toInt(&ok,16);
    return appId;
}

QString decToHex(int decnum)
{
    QString hexadecimal; hexadecimal.setNum(decnum,16);
    return hexadecimal;
}
