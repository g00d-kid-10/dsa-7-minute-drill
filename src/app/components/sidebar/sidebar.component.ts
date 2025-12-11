import { Component, EventEmitter, Output } from '@angular/core';
import { ProblemService } from '../../problem.service';

@Component({
  selector: 'app-sidebar',
  templateUrl: './sidebar.component.html',
})
export class SidebarComponent {
  @Output() problemSelected = new EventEmitter<any>();
  problems: any[] = [];

  constructor(private problemService: ProblemService) {}

  ngOnInit() {
    this.problemService.getProblems().subscribe(data => {
      this.problems = data;
    });
  }

  select(p: any) {
    this.problemSelected.emit(p);
  }
}