#ifndef CREATESECRETWIDGET_H
#define CREATESECRETWIDGET_H

#include <QFrame>
#include <QLineEdit>

class CreateSecretWidget : public QFrame
{
    Q_OBJECT
public:
    CreateSecretWidget(QWidget* parent = nullptr);

private slots:
    void createSecret();
    void copySecret();
private:
    QLineEdit* _message_input;
    QLineEdit* _secret_input;
    QLineEdit* _result;


};

#endif // CREATESECRETWIDGET_H
