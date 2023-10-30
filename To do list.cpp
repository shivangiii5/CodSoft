#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Task{

    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

//Add task description

void addTask(vector<Task>& tasks,string& description){

    Task task(description);
    tasks.push_back(task);
    cout<<"\tTask added: "<<description<<endl;

}

//View all tasks

void viewTasks(vector<Task>& tasks){

    cout<<"\tYour To-Do List:"<<endl<<endl;

    if(tasks.size()==0){
        cout<<"\tNo tasks currently"<<endl;
    }

    for(int i=0;i<tasks.size();i++){
        cout<<"\t"<<i+1<<". ";
        if(tasks[i].completed){
            cout <<"[Completed] ";
        }
        cout<<tasks[i].description<<endl;
    }
}

//Mark a task as completed

void taskCompleted(vector<Task>& tasks,int taskIndex){

    if(taskIndex>=1 && taskIndex<=tasks.size()){
        tasks[taskIndex-1].completed = true;
        cout<<"\tTask marked as completed: "<<tasks[taskIndex - 1].description<<endl;
    }
    else{
        cout<<"\tInvalid task number"<<endl;
    }
}

//Delete a task

void deleteTask(vector<Task>& tasks,int taskIndex){

    if (taskIndex>=1 && taskIndex<=tasks.size()){
        cout<<"\tTask deleted: "<<tasks[taskIndex - 1].description<<endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
    }
    else{
        cout<<"\tInvalid task number"<<endl;
    }
}

int main(){

	cout<<"---------------- My To-Do List -----------------"<<endl<<endl;

	vector<Task> todoList;

    while(true){

        cout<<endl;
        cout<<"\t1. Add Task"<<endl;
        cout<<"\t2. View Tasks"<<endl;
        cout<<"\t3. Mark Task as Completed"<<endl;
        cout<<"\t4. Delete Task"<<endl;
        cout<<"\t5. Quit"<<endl;
        cout<<"\tEnter your choice: ";

        int choice;
        cin>>choice;
        cout<<endl;
        cin.ignore(); //remove undesirable characters from input buffer

        switch(choice){

            case 1:{
                cout<<"\tEnter task description: ";
                string description;
                getline(cin, description);
                addTask(todoList, description);
                break;
            }

            case 2:{
                viewTasks(todoList);
                break;
            }

            case 3:{
                cout<<"\tEnter the task number to be marked as complete: ";
                int taskIndex;
                cin>>taskIndex;
                taskCompleted(todoList, taskIndex);
                break;
            }

            case 4:{
                cout<<"\tEnter the task number to be deleted: ";
                int taskIndex;
                cin>>taskIndex;
                deleteTask(todoList, taskIndex);
                break;
            }

            case 5:{
                cout<<"\tExiting program."<<endl;
                return 0;
            }

            default:{
                cout<<"\tInvalid choice. Please select a valid option."<<endl;
            }
        }
    }
}


