#include "RevealSecretWidget.h"
#include "Encoder.h"

#include <QPushButton>
#include <QVBoxLayout>

RevealSecretWidget::RevealSecretWidget(QWidget *parent)
    : QFrame(parent)
{
    QLayout* layout = new QVBoxLayout(this);

    setFrameStyle(QFrame::Box);

    _message_input = new QLineEdit(this);
    layout->addWidget(_message_input);

    _result = new QLineEdit(this);
    _result->setReadOnly(true);
    layout->addWidget(_result);

    QSpacerItem* _spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(_spacer);

    QPushButton* _reveal_secret_button = new QPushButton("Reveal Secret", this);
    layout->addWidget(_reveal_secret_button);

    QObject::connect(_reveal_secret_button,
                     & QPushButton::clicked,
                     this,
                     & RevealSecretWidget::revealSecret,
                     Qt::DirectConnection);
}

void RevealSecretWidget::revealSecret()
{
    QString message = _message_input->text();
    QString secret = encoder::extract_secret(message);
    _result->setText(secret);
}
