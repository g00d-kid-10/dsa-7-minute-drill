import { Component, HostListener, EventEmitter, Output, ElementRef, ViewChildren, QueryList } from '@angular/core';
import { ProblemService } from '../../problem.service';

@Component({
  selector: 'app-sidebar',
  templateUrl: './sidebar.component.html',
  styleUrls: ['./sidebar.component.css']
})
export class SidebarComponent {
  @Output() problemSelected = new EventEmitter<any>();
  @ViewChildren('problemItem') items!: QueryList<ElementRef>;

  selectedIndex : number;
  problem : any | null;
  problems: any[];
  reversed: boolean = false;

  constructor(private problemService: ProblemService) {
    this.selectedIndex = -1;
    this.problem = null;
    this.problems = [];
  }

  ngOnInit() {
    this.problemService.getProblems().subscribe(data => {
      this.problems = data;
    });
  }

  select(selectedIndex : number) {
    if(selectedIndex < 0 || selectedIndex >= this.problems.length) return;
    this.selectedIndex = selectedIndex;
    this.problem = this.problems[selectedIndex]
    this.problemSelected.emit(this.problem);
    this.scrollToSelected();
  }

  prevProblem() {
    if(this.selectedIndex <= 0) return;
    this.selectedIndex--;
    this.select(this.selectedIndex);
  }

  nextProblem() {
    if(this.selectedIndex >= this.problems.length - 1) return;
    this.selectedIndex++;
    this.select(this.selectedIndex);
  }

  toggleOrder() {
    this.reversed = !this.reversed;
    this.problems = this.problems.reverse();
    this.selectedIndex = this.problems.length - 1 - this.selectedIndex;
    this.problem = this.problems[this.selectedIndex];
    this.problemSelected.emit(this.problem);
    this.scrollToSelected();
  }

  scrollToSelected() {
    setTimeout(() => {
      const el = this.items.get(this.selectedIndex)?.nativeElement;
      el?.scrollIntoView({
        behavior: 'smooth',
        block: 'center'
      });
    });
  }

  @HostListener('window:keydown', ['$event'])
  handleKeyboardEvent(event: KeyboardEvent) {
    if (event.key === 'ArrowLeft') {
      event.preventDefault();   // Stop cursor moving
      this.prevProblem();
    } 
    else if (event.key === 'ArrowRight') {
      event.preventDefault();   // Stop cursor moving
      this.nextProblem();
    }
  }
}