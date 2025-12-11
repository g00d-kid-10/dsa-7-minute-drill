import { Component, Input } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  selectedProblem: string | null = null;

  onProblemSelected(p: string) {
    this.selectedProblem = p;
  }
}