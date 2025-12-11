import { Component, Input } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-code-view',
  templateUrl: './code-view.component.html'
})
export class CodeViewComponent {

  @Input() problem: any = null;

  markdownContent: string = '';
  codeContent: string = '';

  constructor(private http: HttpClient) {}

  ngOnChanges() {
    if (!this.problem) return;

    // Load markdown
    this.http.get(this.problem.markdown, { responseType: 'text' })
      .subscribe(data => this.markdownContent = data);

    // Load code file
    this.http.get(this.problem.code, { responseType: 'text' })
      .subscribe(data => this.codeContent = data);
  }
}
