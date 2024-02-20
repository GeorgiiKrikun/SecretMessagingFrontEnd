#ifndef REVEALSECRETWIDGET_H
#define REVEALSECRETWIDGET_H

#include <QFrame>
#include <QLineEdit>

class RevealSecretWidget : public QFrame
{
    Q_OBJECT
public:
    explicit RevealSecretWidget(QWidget *parent = nullptr);

private slots:
    void revealSecret();

private:
    QLineEdit* _message_input;
    QLineEdit* _result;
signals:
};





#endif // REVEALSECRETWIDGET_H
