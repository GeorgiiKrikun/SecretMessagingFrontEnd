#include "RevealSecretWidget.h"
#include "Encoder.h"

#include <QApplication>
#include <QPushButton>
#include <QStyle>
#include <QVBoxLayout>

RevealSecretWidget::RevealSecretWidget(QWidget *parent)
    : QFrame(parent)
{
    QLayout* layout = new QVBoxLayout(this);

    setFrameStyle(QFrame::Box);

    QWidget* _container = new QWidget(this);
    layout->addWidget(_container);
    QHBoxLayout* _container_layout = new QHBoxLayout(_container);

    _message_input = new QLineEdit(this);
    _container_layout->addWidget(_message_input);
    _message_input->setPlaceholderText("Paste the string with secret message here");

    QPushButton* _paste_secret_button = new QPushButton("", this);
    QIcon openIcon = QApplication::style()->standardIcon(QStyle::SP_DriveFDIcon);
    _paste_secret_button->setIcon(openIcon);
    _container_layout->addWidget(_paste_secret_button);


    QPushButton* _reveal_secret_button = new QPushButton("Reveal Secret", this);
    layout->addWidget(_reveal_secret_button);

    _result = new QLineEdit(this);
    _result->setReadOnly(true);
    layout->addWidget(_result);

    QSpacerItem* _spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(_spacer);



    QObject::connect(_reveal_secret_button,
                     & QPushButton::clicked,
                     this,
                     & RevealSecretWidget::revealSecret,
                     Qt::DirectConnection);

    QObject::connect(_paste_secret_button,
                     & QPushButton::clicked,
                     this,
                     & RevealSecretWidget::pasteSecret,
                     Qt::DirectConnection);
}

void RevealSecretWidget::revealSecret()
{
    QString message = _message_input->text();
    QString secret = encoder::extract_secret(message);
    _result->setText(secret);
}

void RevealSecretWidget::pasteSecret()
{
    _message_input->selectAll();
    _message_input->paste();
    _message_input->deselect();
}
