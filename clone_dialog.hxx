//-------------------------------------------------------------------------//
//         ROS Timetable Editor Clone Service Application Window           //
//                                                                         //
// This file provides part of the source code towards the standalone       //
// timetable editor constructed using the Qt v5.14 framework.              //
// for Railway Operation Simulator, a railway signalling simulation        //
// by Albert Ball, Copyright (c) 2010 [original development].              //
//                                                                         //
// Copyright (C) 2020 Kristian Zarebski                                    //
//                                                                         //
// This program is free software: you can redistribute it and/or modify    //
// it under the terms of the GNU General Public License as published by    //
// the Free Software Foundation, either version 3 of the License, or       //
// (at your option) any later version.                                     //
//                                                                         //
// This program is distributed in the hope that it will be useful,         //
// but WITHOUT ANY WARRANTY; without even the implied warranty of          //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           //
// GNU General Public License for more details.                            //
//                                                                         //
// You should have received a copy of the GNU General Public License       //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.   //
//                                                                         //
// Efforts to improve on this application are welcomed, with the request   //
// that any improvements you deem notable be offered back to the           //
// original project.                                                       //
//                                                                         //
//-------------------------------------------------------------------------//

#ifndef CLONE_DIALOG_HXX
#define CLONE_DIALOG_HXX

#include <QDialog>
#include <QTableWidget>

#include "rosservice.hxx"
#include "rostimetable.hxx"

namespace Ui {
class CloneDialog;
}

class CloneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloneDialog(QWidget *parent = nullptr);
    ~CloneDialog();
    void fwdCurrentService(ROSTimetable* ttb, ROSService* service, QTableWidget* ttb_table){_current_ttb = ttb; _ttb_table = ttb_table; _current_srv = service;}
    void fwdServicesList(QStringList& services){_current_service_list = services;}
    ROSService* getNewService() const {return _cloned_srv;}
    void setInitialValues();
private slots:
    void on_buttonBoxClone_accepted();
    void on_buttonBoxClone_rejected();

private:
    Ui::CloneDialog *ui;
    ROSTimetable* _current_ttb = nullptr;
    QTableWidget* _ttb_table = nullptr;
    ROSService* _current_srv = nullptr;
    ROSService* _cloned_srv = nullptr;
    QStringList _current_service_list = {};
    bool _check_new();
    void _create_clone();
    QString _create_new_id(const QString& current_id);
};

#endif // CLONE_DIALOG_HXX