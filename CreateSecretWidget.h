#ifndef CREATESECRETWIDGET_H
#define CREATESECRETWIDGET_H

#include <QWidget>

#include <QLineEdit>

class CreateSecretWidget : public QWidget
{
    Q_OBJECT
public:
    CreateSecretWidget(QWidget* parent = nullptr);

private slots:
    void createSecret();

private:
    QLineEdit* _message_input;
    QLineEdit* _secret_input;
    QLineEdit* _result;


};

#endif // CREATESECRETWIDGET_H