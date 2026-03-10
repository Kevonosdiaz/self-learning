package main

import (
	"fmt"
	"os"

	tea "charm.land/bubbletea/v2"
)

// Application model/state
type model struct {
	choices  []string
	cursor   int
	selected map[int]struct{}
}

func initialModel() model {
	return model{
		choices:  []string{"Carrots", "Celery", "Kohlrabi"},
		selected: make(map[int]struct{}),
	}
}

func (m model) Init() tea.Cmd {
	return nil
}

// Update method for handling events
func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyPressMsg:
		switch msg.String() {
		// End application
		case "ctrl+c", "q":
			return m, tea.Quit

		// Arrow keys
		case "up", "k":
			if m.cursor > 0 {
				m.cursor--
			}

		case "down", "j":
			if m.cursor < len(m.choices)-1 {
				m.cursor++
			}

		// Toggle item
		case "enter", "space":
			_, ok := m.selected[m.cursor]
			if ok {
				delete(m.selected, m.cursor)
			} else {
				m.selected[m.cursor] = struct{}{}
			}

		}
	}
	return m, nil
}

// Handle the view shown in TUI
func (m model) View() tea.View {
	s := "What to buy?\n\n"

	for i, choice := range m.choices {
		// Is cursor pointing at current choice?
		cursor := " "
		if m.cursor == i {
			cursor = ">"
		}

		// Is current choice selected?
		checked := " "
		if _, ok := m.selected[i]; ok {
			checked = "x"
		}

		// Render row
		s += fmt.Sprintf("%s [%s] %s\n", cursor, checked, choice)

	}

	// Append footer text
	s += "\nPress q to quit.\n"

	// Return view to return
	return tea.NewView(s)
}

func main() {
	p := tea.NewProgram(initialModel())
	if _, err := p.Run(); err != nil {
		fmt.Printf("Error while running Bubble Tea program!: %v", err)
		os.Exit(1)
	}
}
