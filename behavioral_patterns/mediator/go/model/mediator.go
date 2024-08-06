package model

// Concrete mediator.
type CorporateMessenger struct {
	colleagues []Colleague
}

func (m *CorporateMessenger) AddColleagues(c []Colleague) {
	m.colleagues = c
}

func (m *CorporateMessenger) SendMessage(sender Colleague, text string) {
	for _, col := range m.colleagues {
		_, isRecipientLeader := col.(*Leader)
		_, isSenderLeader := sender.(*Leader)

		if isRecipientLeader && !isSenderLeader {
			continue
		}

		if sender != col {
			col.receivedMessage(sender, text)
		}
	}
}
