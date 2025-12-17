import { Component, ViewChild, ElementRef } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  selectedProblem: string | null = null;
  @ViewChild('sidebar', { static: true }) sidebar!: ElementRef;

  onProblemSelected(p: string) {
    this.selectedProblem = p;
  }


  startResize(event: MouseEvent) {
    event.preventDefault();

    const startX = event.clientX;
    const startWidth = this.sidebar.nativeElement.offsetWidth;

    const onMouseMove = (e: MouseEvent) => {
      const newWidth = startWidth + (e.clientX - startX);
      this.sidebar.nativeElement.style.width = `${newWidth}px`;
    };

    const onMouseUp = () => {
      document.removeEventListener('mousemove', onMouseMove);
      document.removeEventListener('mouseup', onMouseUp);
    };

    document.addEventListener('mousemove', onMouseMove);
    document.addEventListener('mouseup', onMouseUp);
  }
}