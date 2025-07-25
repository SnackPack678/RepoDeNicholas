#include <wx/wx.h>
#include "Task.h" // <- Task.h is a copy/paste of the Task class from TaskManager™

#include <vector> // Using vectors here to dynamically change the size of taskList

std::vector<Task> taskList;

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    wxTextCtrl* titleInput;
    wxTextCtrl* descInput;
    wxTextCtrl* priInput;

    void OnCreateTask(wxCommandEvent& event);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("TaskManager™ GUI");// Added my Program's name on the window
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, "Title (max 20):", wxPoint(20, 20));      // Set Title
    titleInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 20), wxSize(200, -1));

    wxStaticText* descLabel = new wxStaticText(panel, wxID_ANY, "Description (max 75):", wxPoint(20, 60)); // Set Description 
    descInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 60), wxSize(200, -1));

    wxStaticText* priLabel = new wxStaticText(panel, wxID_ANY, "Priority (1-10):", wxPoint(20, 100));      // Set Priority
    priInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 100), wxSize(200, -1));

    wxButton* createButton = new wxButton(panel, wxID_ANY, "Create Task", wxPoint(150, 150));              // Create Task Button
    createButton->Bind(wxEVT_BUTTON, &MyFrame::OnCreateTask, this);
}

void MyFrame::OnCreateTask(wxCommandEvent& event) {
    wxString title = titleInput->GetValue();
    wxString desc = descInput->GetValue();
    wxString priStr = priInput->GetValue();

    if (title.IsEmpty() || title.Length() > 20) {                                            // Error checker for Title
        wxMessageBox("Title must be 1-20 characters.", "Error", wxOK | wxICON_ERROR);        
        return;
    }
    if (desc.IsEmpty() || desc.Length() > 75) {                                              // Error checker for Description
        wxMessageBox("Description must be 1-75 characters.", "Error", wxOK | wxICON_ERROR);    
        return;
    }

    long priority;
    if (!priStr.ToLong(&priority) || priority < 1 || priority > 10) {                        // Error checker for Priority
        wxMessageBox("Priority must be a number from 1-10.", "Error", wxOK | wxICON_ERROR); 
        return;
    }

  
    Task t(std::string(title.mb_str()), std::string(desc.mb_str()), (short)priority);       // Task Constructor 
    taskList.push_back(t);                                                                  // taskList grows by one(1)

    wxMessageBox("Task created successfully!", "Success", wxOK | wxICON_INFORMATION);       // Confirmation message

    
    titleInput->Clear(); // clear title input
    descInput->Clear();  // clear description input
    priInput->Clear();   // clear priority input
}

